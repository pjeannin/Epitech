import React, {Component} from 'react';
import axios from "axios";
import {Typography} from "@mui/material";
const config = require('../json/config.json')

class YoutubeChannel extends Component {
    constructor(props) {
        super(props);
        this.state = {
            messages: []
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Reddit/messages`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                headers: {},
                params: {
                    username: localStorage.getItem('username'),
                    type: this.props.params[0].data,
                }
            }
        }).then(response => {
            this.setState({
                messages: response.data.data.children
            });
        }).catch(e => {
            if (e.response.status !== 401) {
                let shouldReload = localStorage.getItem('reddit') === 'true';
                localStorage.setItem('reddit', 'false');
                if (shouldReload) {
                    window.location.reload();
                    alert('Please authorize your reddit account again.');
                }
            }
            console.log(e)
        });
    }

    componentDidMount() {
        this.getData();
    }

    render() {
        return (
            <div>
                <h5>{this.props.params[0].data} Messages</h5>
                {this.props.params[0].data !== 'inbox' && this.props.params[0].data !== 'sent' && this.props.params[0].data !== 'unread'
                    && <Typography>Please set a valid type of message (sent, unread, inbox)</Typography>}
                {this.state.messages.map((message, index) => {
                    return (
                        <div key={index}>
                            <Typography sx={{fontWeight: 'bold'}}>{message.data.subject}</Typography>
                            <Typography noWrap={true}>{message.data.body}</Typography>
                        </div>
                    )
                })}
            </div>
        );
    }
}

export default YoutubeChannel;