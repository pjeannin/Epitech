import React from 'react';
import axios from "axios";
import '../CSS/Widget.css';
import Box from "@mui/material/Box";
import NumberFormat from "react-number-format";
const config = require('../json/config.json')

class CurrentWeather extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            title: "",
            duration: "",
            image: "",
            views: 0,
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Pornhub/VideoInfos`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                params: {
                    id: this.props.id,
                }
            }
        })
            .then(response => {
                this.setState({
                    title: response.data.video.title,
                    duration: response.data.video.duration,
                    image: response.data.video.thumb,
                    views: response.data.video.views,
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
                <div style={{display: 'flex', flexDirection: 'row', marginBottom: 8}}>
                    <img style={{height: 120, width: 150, borderRadius: 10}} src={this.state.image} alt=""/>
                    <div style={{marginLeft: 5}}>
                        <h4>Duration</h4>
                        <span>{this.state.duration}</span>
                        <h4>Views</h4>
                        <NumberFormat value={this.state.views} displayType={'text'} thousandSeparator={true}/>
                    </div>
                </div>
                <Box sx={{ typography: 'subtitle2', fontWeight: 'bold' }}>{this.state.title}</Box>
            </div>
        );
    }
}

export default CurrentWeather;