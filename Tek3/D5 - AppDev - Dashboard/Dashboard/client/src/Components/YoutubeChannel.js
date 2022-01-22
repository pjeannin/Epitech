import React, {Component} from 'react';
import axios from "axios";
import NumberFormat from "react-number-format";
import {Typography} from "@mui/material";
const config = require('../json/config.json')

class YoutubeChannel extends Component {
    constructor(props) {
        super(props);
        this.state = {
            subscribers: 0,
            channelName: '',
            viewCount: 0,
            image: '',
            videoCount: 0
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Youtube/ChannelInfos`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                headers: {},
                params: {
                    q: this.props.params[0].data,
                }
            }
        }).then(response => {
            this.setState({
                image: response.data.items[0].snippet.thumbnails.default.url,
                channelName: response.data.items[0].snippet.title,
                subscribers: response.data.items[0].statistics.subscriberCount,
                viewCount: response.data.items[0].statistics.viewCount,
                videoCount: response.data.items[0].statistics.videoCount
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
                <div style={{display: 'flex', flexDirection: 'row', marginBottom: 8}}>
                    <img style={{height:100, width: 100, borderRadius: 100}} src={this.state.image} alt=""/>
                    <div style={{marginLeft: 10}}>
                        <h5>Channel Name</h5>
                        <p>{this.state.channelName}</p>
                    </div>
                </div>
                <div style={{display: 'flex', flexDirection: 'row', marginBottom: 8, justifyContent: 'space-between',}}>
                    <div>
                        <h5>Subscribers</h5>
                        {/*<NumberFormat value={this.state.subscribers} displayType={'text'} thousandSeparator={true}/>*/}
                        <Typography>{this.state.subscribers}</Typography>
                    </div>
                    <div>
                        <h5>Video Count</h5>
                        <NumberFormat value={this.state.videoCount} displayType={'text'} thousandSeparator={true}/>
                    </div>
                    <div>
                        <h5>View Count</h5>
                        <NumberFormat value={this.state.viewCount} displayType={'text'} thousandSeparator={true}/>
                    </div>
                </div>
            </div>
        );
    }
}

export default YoutubeChannel;