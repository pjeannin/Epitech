import React from 'react';
import axios from "axios";
import Typography from "@mui/material/Typography";
const config = require('../json/config.json')

class AirQuality extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            city: '',
            country: '',
            region: '',
            air_quality: '',
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Weather/AirQuality`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                params: {
                    q: this.props.params[0].data,
                    aqi: "yes",
                }
            }
        })
            .then(response => {
                this.setState({
                    city: response.data.location.name,
                    country: response.data.location.country,
                    region: response.data.location.region,
                    air_quality: response.data.current.air_quality,
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
                <div style={{display: 'flex', flexDirection: 'row', justifyContent: 'space-around', alignItems: 'center'}}>
                    <div>
                        <Typography>{this.state.city}</Typography>
                        <Typography>{this.state.country}</Typography>
                        <Typography>{this.state.region}</Typography>
                    </div>
                    <div>
                        <p>Carbon Monoxide : {Math.round(this.state.air_quality.co * 100) / 100}μg/m3</p>
                        <p>Ozone : {Math.round(this.state.air_quality.o3 * 100) / 100}μg/m3</p>
                        <p>Nitrogen Dioxide : {Math.round(this.state.air_quality.no2 * 100) / 100}μg/m3</p>
                        <p>Sulphur Dioxide : {Math.round(this.state.air_quality.so2 * 100) / 100}μg/m3</p>
                        <p>PM10 : {Math.round(this.state.air_quality.pm10 * 100) / 100}μg/m3</p>
                        <p>PM2.5 : {Math.round(this.state.air_quality.pm2_5 * 100) / 100}μg/m3</p>
                        <p>Air Quality Index : {this.state.air_quality["us-epa-index"]}/10</p>
                    </div>
                </div>
            </div>
        );
    }
}

export default AirQuality;