import React, {Component} from 'react';
import axios from "axios";
import ColoredLine from "./ColoredLine";
import {withStyles} from "@material-ui/core";
import {Typography} from "@mui/material";
const config = require('../json/config.json')

const WhiteTextTypography = withStyles({
    root: {
        color: "#FFFFFF"
    }
})(Typography);

class GithubUserRepos extends Component {
    constructor(props) {
        super(props);
        this.state = {
            repos: [],
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Github/UserRepos`, {
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
                repos: response.data
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
                <WhiteTextTypography sx={{fontWeight: 'bold'}}>Number of Repos</WhiteTextTypography>
                <WhiteTextTypography>{this.state.repos.length}</WhiteTextTypography>
                <ColoredLine color="white"/>
                {this.state.repos.map((repo, index) => {
                    return (
                        <div key={index}>
                            <WhiteTextTypography sx={{fontWeight: 'bold' }}>{repo.name}</WhiteTextTypography>
                            <WhiteTextTypography>{repo.description}</WhiteTextTypography>
                            <ColoredLine color="white"/>
                        </div>
                    )
                })}
            </div>
        );
    }
}

export default GithubUserRepos;