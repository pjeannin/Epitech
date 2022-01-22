import React from 'react';
import axios from "axios";
const config = require('../json/config.json')

class CurrentWeather extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            city: '',
            country: '',
            region: '',
            temp: 0,
            feel_temp: 0,
            cloud: 0,
            wind: 0,
            humidity: 0,
            condition: {
                text: '',
                icon: ''
            }
        };
    }

    getData() {
        axios.get(`${config.expressIP}/api/update/Weather/CurrentWeather`, {
            headers: {
                'auth-token': this.props.token,
            },
            params: {
                params: {
                    q: this.props.params[0].data,
                    aqi: "no",
                }
            }
        })
        .then(response => {
            this.setState({
                city: response.data.location.name,
                country: response.data.location.country,
                region: response.data.location.region,
                temp: response.data.current.temp_c,
                feel_temp: response.data.current.feelslike_c,
                cloud: response.data.current.cloud,
                wind: response.data.current.wind_kph,
                humidity: response.data.current.humidity,
                condition: {
                    text: response.data.current.condition.text,
                    icon: response.data.current.condition.icon
                }
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
                        <img src={this.state.condition.icon} alt={this.state.condition.text} />
                        <p>{this.state.condition.text}</p>
                    </div>
                    <div>
                        <p>{this.state.city}</p>
                        <p>{this.state.country}</p>
                        <p>{this.state.region}</p>
                        <p>Temperature : {this.state.temp}°C</p>
                        <p>Feels like : {this.state.feel_temp}°C</p>
                        <p>Clouds : {this.state.cloud}%</p>
                        <p>Wind : {this.state.wind}km/h</p>
                        <p>Humidity : {this.state.humidity}%</p>
                    </div>
                </div>

            </div>
        );
    }
}

export default CurrentWeather;