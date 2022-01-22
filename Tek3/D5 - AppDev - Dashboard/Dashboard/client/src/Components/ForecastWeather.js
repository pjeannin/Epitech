import React from 'react';
import axios from "axios";
import {Typography} from "@mui/material";
const config = require('../json/config.json')

class ForecastWeather extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            forecast: [],
            city: '',
            country: '',
            region: '',
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Weather/ForecastWeather`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                headers: {},
                params: {
                    q: this.props.params[0].data,
                    alerts: "no",
                    aqi: "no",
                    days: this.props.params[1].data
                }
            }
        }).then(response => {
            this.setState({
                forecast: response.data.forecast.forecastday,
                city: response.data.location.name,
                country: response.data.location.country,
                region: response.data.location.region
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
                <p>{this.state.city}</p>
                <p>{this.state.country}</p>
                <p>{this.state.region}</p>
                <div>
                    {this.state.forecast.map((forecast, index) => {
                        return (
                            <div key={index} style={{marginTop: 5}}>
                                <p>{forecast.date}</p>
                                <div style={{display: 'flex', flexDirection: 'row', justifyContent: 'space-around', alignItems: 'center'}}>
                                    <div>
                                        <img src={forecast.day.condition.icon} alt={forecast.day.condition.text} />
                                        <Typography>    {forecast.day.condition.text}</Typography>
                                    </div>
                                    <div>
                                        <Typography>Min: {forecast.day.mintemp_c}°C</Typography>
                                        <Typography>Max: {forecast.day.maxtemp_c}°C</Typography>
                                        <Typography>Average: {forecast.day.avgtemp_c}°C</Typography>
                                    </div>
                                </div>
                            </div>
                        );
                    })}
                </div>
            </div>
        );
    }
}

export default ForecastWeather;