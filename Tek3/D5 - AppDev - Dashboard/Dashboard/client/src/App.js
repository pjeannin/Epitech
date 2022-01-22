import { BrowserRouter, Switch, Route } from 'react-router-dom'
import HeaderBar from "./Components/Header";
import Home from "./Pages/Home";
import About from "./Pages/About";
import Login from "./Pages/Login";
import Register from "./Pages/Register";
import NotFound from "./Pages/NotFound";
import {useState} from "react";
import AuthRedditCallback from "./Pages/AuthRedditCallback";
import FailLinkReddit from "./Pages/FailLinkReddit";

function App() {
    const [isLoggedIn, setIsLoggedIn] = useState(false)
    const [token, setToken] = useState(null)
    const [about, setAbout] = useState([])

    const handleLogout = () => {
        console.log("Logging out...")
        setIsLoggedIn(false)
        localStorage.setItem('token', '')
        setToken('')
        localStorage.setItem('rememberMe', 'false')
        localStorage.setItem('reddit', 'false')
    }

    const handleLogin = (token, rememberMe, username, redditLogin) => {
        setIsLoggedIn(true)
        localStorage.setItem('rememberMe', rememberMe ? 'true' : 'false')
        localStorage.setItem('token', rememberMe ? token : '')
        localStorage.setItem('username', username);
        localStorage.setItem('reddit', redditLogin ? 'true' : 'false')
        setToken(token)
    }

    if (!isLoggedIn) {
        const token_ = localStorage.getItem('token')
        const rememberMe_ = localStorage.getItem('rememberMe')
        if (token_ !== '' && rememberMe_ === 'true') {
            setIsLoggedIn(true)
            setToken(token_)
        }
    }

    return (
        <div>
            <BrowserRouter>
                <HeaderBar isLoggedIn={isLoggedIn} handleLogout={handleLogout} setAbout={setAbout} />
                <Switch>
                    <Route exact path="/">
                        <Home token={token}/>
                    </Route>
                    <Route exact path="/about">
                        <About about={about}/>
                    </Route>
                    <Route exact path="/login">
                        <Login handleLogin={handleLogin}/>
                    </Route>
                    <Route exact path="/register">
                        <Register />
                    </Route>
                    <Route path="/auth/redditURI">
                        <AuthRedditCallback/>
                    </Route>
                    <Route path="/auth/redditFail">
                        <FailLinkReddit/>
                    </Route>
                    <Route path="*" component={NotFound}/>
                </Switch>
            </BrowserRouter>
        </div>
    );
}

export default App;
