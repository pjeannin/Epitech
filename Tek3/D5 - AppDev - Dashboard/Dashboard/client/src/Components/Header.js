import "../CSS/Header.css";
import * as React from 'react';
import AppBar from '@mui/material/AppBar';
import Box from '@mui/material/Box';
import Toolbar from '@mui/material/Toolbar';
import Button from '@mui/material/Button';
import {withRouter, useLocation, Redirect} from "react-router-dom";
import axios from "axios";
const config = require('../json/config.json')


const goTo = (history, path) => {
    history.push(path);
};


const HeaderBar = props => {
    const history = props.history;
    const location = useLocation();

    if (!props.isLoggedIn && location.pathname !== '/login' && location.pathname !== '/register' && location.pathname !== '/about') {
        return <Redirect push to="/login" />
    }

    return (
        <Box className="header" style={{position: 'sticky', top: 0}} sx={{ flexGrow: 1 }}>
            <AppBar position="static" style={{backgroundColor: "#313132ff"}}>
                <Toolbar>
                    <Button color="inherit" style={{ marginRight: 20 }} onClick={() => goTo(history, '/')}>Dashboard</Button>
                    <Button color="inherit" onClick={() => {
                        axios.get(`${config.expressIP}/about.json`)
                            .then(function (response) {
                                props.setAbout(response.data);
                                goTo(history, '/about');
                            })
                            .catch(function (error) {
                                console.log(error);
                            });
                    }}>About.json</Button>
                    <div style={{ flexGrow: 1 }} />
                    {(props.isLoggedIn && localStorage.getItem('reddit') === 'false') && <Button style={{marginRight: 20, color: "#ff4500"}} onClick={() => {
                        axios.get(`${config.expressIP}/api/user/redditOauth`)
                            .then(function (response) {
                                window.open(response.data.authUrl, '_self');
                            })
                            .catch(function (error) {
                                console.log(error);
                            });
                    }}>Link Reddit account</Button>}
                    {props.isLoggedIn && <Button color="inherit" onClick={() => {
                        goTo(history, '/login')
                        props.handleLogout()
                    }}>Sign out</Button>}
                    {!props.isLoggedIn && <Button color="inherit" onClick={() => goTo(history, '/login')}>Sign In</Button>}
                </Toolbar>
            </AppBar>
        </Box>
    );
}

export default withRouter(HeaderBar);