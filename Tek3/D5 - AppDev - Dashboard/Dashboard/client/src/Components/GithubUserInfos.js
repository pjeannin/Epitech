import React, {Component} from 'react';
import axios from "axios";
import {Typography} from "@mui/material";
import {withStyles} from "@material-ui/core";
const config = require('../json/config.json')

const WhiteTextTypography = withStyles({
    root: {
        color: "#FFFFFF"
    }
})(Typography);

class GithubUserInfos extends Component {
    constructor(props) {
        super(props);
        this.state = {
            user: {},
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Github/UserInfos`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                headers: {},
                params: {
                    username: this.props.params[0].data,
                }
            }
        }).then(response => {
            this.setState({
                user: response.data
            });
        }).catch(e => {
            console.log(e)
        });
    }

    componentDidMount() {
        this.getData();
    }

    render() {
        return (
            <div>
                <div style={{display: 'flex', flexDirection: 'row', marginBottom: 5}}>
                    <img style={{height: 100, borderRadius: 100}} src={this.state.user.avatar_url} alt="User Avatar"/>
                    <div style={{marginLeft: 5}}>
                        <WhiteTextTypography sx={{fontWeight: 'bold' }}>Username</WhiteTextTypography>
                        <WhiteTextTypography>{this.state.user.login}</WhiteTextTypography>
                        {this.state.user.name != null && <p>Name: {this.state.user.name}</p>}
                        {this.state.user.location != null && <p>Location: {this.state.user.location}</p>}
                        {this.state.user.email != null && <p>Email: {this.state.user.email}</p>}
                        {this.state.user.bio != null && <p>Bio: {this.state.user.bio}</p>}
                    </div>
                </div>
                <div style={{display: 'flex', flexDirection: 'row', justifyContent: 'space-between',}}>
                    <div>
                        <WhiteTextTypography sx={{fontWeight: 'bold' }}>Public repos</WhiteTextTypography>
                        <WhiteTextTypography>{this.state.user.public_repos}</WhiteTextTypography>
                    </div>
                    <div>
                        <WhiteTextTypography sx={{fontWeight: 'bold' }}>Followers</WhiteTextTypography>
                        <WhiteTextTypography>{this.state.user.followers}</WhiteTextTypography>
                    </div>
                    <div>
                        <WhiteTextTypography sx={{fontWeight: 'bold' }}>Following</WhiteTextTypography>
                        <WhiteTextTypography>{this.state.user.following}</WhiteTextTypography>
                    </div>
                </div>
            </div>
        );
    }
}

export default GithubUserInfos;