import * as React from 'react';
import Avatar from '@mui/material/Avatar';
import Button from '@mui/material/Button';
import CssBaseline from '@mui/material/CssBaseline';
import TextField from '@mui/material/TextField';
import Box from '@mui/material/Box';
import LockOutlinedIcon from '@mui/icons-material/LockOutlined';
import Typography from '@mui/material/Typography';
import Container from '@mui/material/Container';
import { createTheme, ThemeProvider } from '@mui/material/styles';
import { withRouter} from "react-router-dom";
import axios from "axios";
import Checkbox from "@mui/material/Checkbox";
import FormControlLabel from "@mui/material/FormControlLabel";
const config = require('../json/config.json')

const theme = createTheme();

const Login = props => {
    const {history} = props;
    let condition = false;
    let age = false;
    const passwordCheck = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,20}$/
    const emailCheck = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;

    const handleSubmit = (event) => {
        event.preventDefault();
        const data = new FormData(event.currentTarget);
        if (!condition) {
            alert("You must agree to the terms and conditions");
            return;
        } else if (!age) {
            alert('You must be at least 18 years old');
            return;
        } else if (!data.get('email').match(emailCheck)) {
            alert('Invalid email address');
            return;
        } else if (!data.get('password').match(passwordCheck)) {
            alert('The password must be between 6 to 20 characters long and contain at least one numeric digit, one uppercase and one lowercase letter');
        } else if (data.get('password') !== data.get('password-confirm')) {
            alert('The password confirmation does not match the password');
        } else {
            axios.post(`${config.expressIP}/api/user/register`, {
                username: data.get('username'),
                email: data.get('email'),
                password: data.get('password')
            }, {
                headers: {
                    'Access-Control-Allow-Origin' : '*'
                }
            }).then((r) => {
                history.push('/login')
            }).catch(e => {
                console.log(e);
                alert('Something went wrong');
            });
        }
        console.log({
            email: data.get('email'),
            password: data.get('password'),
            password_confirmation: data.get('password-confirm'),
            username: data.get('username')
        });
    };

    return (
        <ThemeProvider theme={theme}>
            <Container component="main" maxWidth="xs">
                <CssBaseline />
                <Box
                    sx={{
                        marginTop: 8,
                        display: 'flex',
                        flexDirection: 'column',
                        alignItems: 'center',
                    }}
                >
                    <Avatar sx={{ m: 1, bgcolor: 'secondary.main' }}>
                        <LockOutlinedIcon />
                    </Avatar>
                    <Typography component="h1" variant="h5">
                        Sign up
                    </Typography>
                    <Box component="form" onSubmit={handleSubmit} noValidate sx={{ mt: 1 }}>
                        <TextField
                            margin="normal"
                            required
                            fullWidth
                            id="username"
                            label="Username"
                            name="username"
                            autoComplete="username"
                            autoFocus
                        />
                        <TextField
                            margin="normal"
                            required
                            fullWidth
                            id="email"
                            label="Email Address"
                            name="email"
                            autoComplete="email"
                            autoFocus
                        />
                        <TextField
                            margin="normal"
                            required
                            fullWidth
                            name="password"
                            label="Password"
                            type="password"
                            id="password"
                            autoComplete="new-password"
                        />
                        <TextField
                            margin="normal"
                            required
                            fullWidth
                            name="password-confirm"
                            label="Confirm Password"
                            type="password"
                            id="password-confirm"
                            autoComplete="new-password"
                        />
                        <FormControlLabel
                            control={<Checkbox value="remember" color="primary" onChange={(e) => condition = e.target.checked} />}
                            label="I accept the terms and conditions."
                        />
                        <FormControlLabel
                            control={<Checkbox value="remember" color="primary" onChange={(e) => age = e.target.checked} />}
                            label="Yes, I am older than 18."
                        />
                        <Button
                            type="submit"
                            fullWidth
                            variant="contained"
                            sx={{ mt: 3, mb: 2 }}
                        >
                            Sign Up
                        </Button>
                    </Box>
                </Box>
            </Container>
        </ThemeProvider>
    );
}

export default withRouter(Login);