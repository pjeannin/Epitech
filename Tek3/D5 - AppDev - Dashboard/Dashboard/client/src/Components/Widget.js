import React from 'react';
import CurrentWeather from "./CurrentWeather";
import ForecastWeather from "./ForecastWeather";
import AirQuality from "./AirQuality";
import GithubUserInfos from "./GithubUserInfos";
import GithubUserRepos from "./GithubUserRepos";
import createStyles from '@mui/styles/createStyles'
import {IconButton} from "@mui/material";
import EditIcon from '@mui/icons-material/Edit';
import DeleteIcon from '@mui/icons-material/Delete';
import YoutubeChannel from "./YoutubeChannel";
import PornHubVideoInfos from "./PornHubVideoInfos";
import PornHubTopVideos from "./PornHubTopVideos";
import RedditMessages from "./RedditMessages";
import EditWidgetPopup from "./EditWidgetPopup";
import axios from "axios";
import config from "../json/config.json";

class Widget extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            time: Date.now(),
            isEditing: false,
        };
        this.refreshRef = React.createRef();
    }

    componentDidMount() {
        this.interval = setInterval(() => {
            this.setState({time: Date.now()})
            this.refreshRef.current.getData();
        }, parseInt(this.props.widget.widgetData.params[this.props.widget.widgetData.params.length - 1].data) * 1000);
    }

    componentWillUnmount() {
        clearInterval(this.interval);
    }

    displayRightWidget() {
        switch (this.props.widget.serviceName) {
            case 'Weather':
                switch (this.props.widget.widgetData.name) {
                    case "Current weather":
                        return (<CurrentWeather ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    case "Weather forecast":
                        return (<ForecastWeather ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    case "Current air quality":
                        return (<AirQuality ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    default:
                        break;
                }
                break;
            case 'Github':
                switch (this.props.widget.widgetData.name) {
                    case "User Infos":
                        return (<GithubUserInfos ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    case "Repository List":
                        return (<GithubUserRepos ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    default:
                        break;
                }
                break;
            case 'Youtube':
                switch (this.props.widget.widgetData.name) {
                    case "Channel Infos":
                        return (<YoutubeChannel ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    default:
                        break;
                }
                break;
            case 'Pornhub':
                switch (this.props.widget.widgetData.name) {
                    case 'Video infos':
                        return (<PornHubVideoInfos ref={this.refreshRef} id={this.props.widget.widgetData.params[0].data} token={this.props.token}/>);
                    case 'Top videos':
                        return (<PornHubTopVideos ref={this.refreshRef} token={this.props.token}/>);
                    default:
                        break;
                }
                break;
            case 'Reddit':
                switch (this.props.widget.widgetData.name) {
                    case 'Messages':
                        return (<RedditMessages ref={this.refreshRef} params={this.props.widget.widgetData.params} token={this.props.token}/>);
                    default:
                        break;
                }
                break;
            default:
                return (
                    <div>
                        <h4>{this.props.widget.serviceName}</h4>
                        <h6>{this.props.widget.widgetData.name}</h6>
                        <h5>Params</h5>
                        {this.props.widget.widgetData.params.map((param, index) => {
                            return (
                                <div key={index}>
                                    <h6>{param.name}</h6>
                                    <h6>{param.data}</h6>
                                </div>
                            )

                        })}
                    </div>);
        }
    }

    getBackgroundColor(ServiceName) {
        switch (ServiceName) {
            case 'Weather':
                return '#00bcd4';
            case 'Github':
                return '#000000';
            case 'Youtube':
                return '#ff0000';
            case 'Pornhub':
                return '#ff9000';
            case 'Reddit':
                return '#ff4500';
            default:
                return '#313131';
        }
    }

    handleEdit() {
        this.setState({
            isEditing: !this.state.isEditing
        });
    }

    edit(widget, token) {
        axios.patch(`${config.expressIP}/api/widgets/updateWidget`, {
            'widget': widget,
        }, {
            headers: {
                'auth-token': token
            }, params: {
                id: widget._id,
            }
        }).then(response => {
            this.props.loadWidgets().then(() => {
                this.refreshRef.current.getData();
            });
        }).catch(error => {
            console.log(error);
        });
    }

    render() {

        return (
            <div className="position" style={{...styles.widget, ...{backgroundColor: this.getBackgroundColor(this.props.widget.serviceName)}}}>
                <div style={styles.widgetHeader}>
                    <h4>{this.props.widget.serviceName} - {this.props.widget.widgetData.name}</h4>
                    <div>
                        <IconButton aria-label="delete" size="small" onClick={() => this.handleEdit(this.props.widget, this.props.token)}>
                            <EditIcon fontSize="inherit" />
                        </IconButton>
                        <IconButton aria-label="delete" size="small" onClick={() => this.props.handleDelete(this.props.widget, this.props.token)}>
                            <DeleteIcon fontSize="inherit" />
                        </IconButton>
                    </div>
                </div>
                <div style={styles.widgetContent}>
                    {this.displayRightWidget()}
                </div>
                {this.state.isEditing && <EditWidgetPopup token={this.props.token} sendEdit={(widget, token) => this.edit(widget, token)} widget={this.props.widget} close={() => this.handleEdit()}/>}
            </div>
        );
    }
}

const styles = createStyles({
    widget: {
        height: '250px',
        width: '350px',
        overflowY: 'scroll',
        overflowX: 'scroll',
        border: "2px solid grey",
        margin: 10,
        borderRadius: 5
    },

    widgetContent: {
        padding: 10,
    },

    widgetHeader: {
        position: 'sticky',
        top: 0,
        display: 'flex',
        height: '30px',
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
        padding: 10,
        backgroundColor: '#f5f5f5',
        borderRadius: '0 0 8px 8px',
        boxShadow: '0 7px 5px 0 rgba(0,0,0,0.14), 0 2px 5px 0 rgba(0,0,0,0.12), 0 3px 1px -8px rgba(0,0,0,0.2)'
    },
})

export default Widget;