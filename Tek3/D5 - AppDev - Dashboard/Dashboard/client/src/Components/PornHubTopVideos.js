import React from 'react';
import axios from "axios";
import '../CSS/Widget.css';
import {Typography} from "@mui/material";
import Box from "@mui/material/Box";
import NumberFormat from "react-number-format";
const config = require('../json/config.json')

class CurrentWeather extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            video: [],
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Pornhub/TopVideos`, {
            headers: {
                'auth-token': this.props.token,
            },
        })
            .then(response => {
                this.setState({
                    video: response.data.videos,
                });
            })
            .catch(error => {
                console.log(error);
            });
    }

    componentDidMount() {
        this.getData();
    }

    render() {
        return (
            <div>
                {this.state.video.map((video, index) => {
                    return (
                        <div style={{display: 'flex', flexDirection: 'row', marginBottom: 5}}>
                            <img src={video.thumb} alt="thumbnail" style={{height: 120, width: 150, borderRadius: 10}}/>
                            <div style={{marginLeft: 5}}>
                                <Box sx={{ typography: 'subtitle2', fontWeight: 'bold' }}>{video.title}</Box>
                                <Typography style={{marginBottom: 5}}>Duration: {video.duration}</Typography>
                                <NumberFormat value={video.views} displayType={'text'} thousandSeparator={true} suffix=" Views"/>
                            </div>
                        </div>
                    );
                })}
            </div>
        );
    }
}

export default CurrentWeather;