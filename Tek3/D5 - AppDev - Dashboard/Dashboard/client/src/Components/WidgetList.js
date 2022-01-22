import * as React from 'react';
import axios from "axios";
import Widget from "./Widget";
import {DragDropContext, Droppable, Draggable} from "react-beautiful-dnd";
import ImageList from '@material-ui/core/ImageList';
import ImageListItem from '@mui/material/ImageListItem';
import {Button} from "@mui/material";
import NewWidgetPopup from "./NewWidgetPopup";
const config = require('../json/config.json')

class WidgetList extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            widgets: [],
            isEditing: false,
            isCreating: false,
            currentWidget: {},
            about: [],
            isPopupOpen: false
        };
    }

    updateWidgets = (widgets) => {
        this.setState({widgets: widgets});
    };

    componentDidMount() {
        this.loadWidgets();
    }

    async loadWidgets() {
        axios.get(`${config.expressIP}/api/widgets/get`, {
            headers: {
                'auth-token': this.props.token
            },
            params: {
                'user':localStorage.getItem('username'),
            }
        }).then(response => {
            let sortedWidgets = response.data.sort((a, b) => a.index - b.index);
            this.setState({widgets: sortedWidgets});
        }).catch(error => {
            console.log(error);
        });
    }

    sendEdit(widget, token) {
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

    handleOnDragEnd = result => {
        const {destination, source} = result;
        if (!destination) {
            return;
        }
        if (destination.droppableId === source.droppableId && destination.index === source.index) {
            return;
        }
        const start = this.state.widgets.slice(0);
        const [removed] = start.splice(source.index, 1);
        start.splice(destination.index, 0, removed);
        for (let widget in start) {
            start[widget].index = widget;
            this.sendEdit(start[widget], this.props.token);
        }
        this.setState({widgets: start});
    };

    handleDelete(widget, token) {
        axios.delete(`${config.expressIP}/api/widgets/deleteWidget`, {
            headers: {
                'auth-token': token
            },
            params: {
                id: widget._id,
            }
        }).then(response => {
            this.loadWidgets();
        }).catch(error => {
            console.log(error);
        });
    }

    handleEdit(widget, token) {
        this.setState({
            isEditing: !this.state.isEditing,
            currentWidget: widget,
        });
    }

    togglePopup() {
        axios.get(`${config.expressIP}/about.json`)
            .then((response) => {
                this.setState({
                    about: response.data,
                    isPopupOpen: !this.state.isPopupOpen
                });
            })
            .catch(function (error) {
                console.log(error);
            });
    }

    addWidget(service, widget, inputList) {
        let index = 0;
        axios.get(`${config.expressIP}/api/widgets/get`, {
            headers: {
                'auth-token': this.props.token
            },
            params: {
                'user':localStorage.getItem('username'),
            }
        }).then(response => {
            index = response.data.length;
            let data = {
                user: localStorage.getItem('username'),
                serviceName: service,
                index: index,
                widgetData: {
                    name: widget,
                    params: inputList
                },
            }
            axios.post(`${config.expressIP}/api/widgets/create`, data,
                {
                    headers: {
                        'auth-token': this.props.token
                    }
                })
                .then((response) => {
                    this.loadWidgets();
                })
                .catch((error) => {
                    console.log(error);
                });
        }).catch(error => {
            console.log(error);
        });

    }


    render() {

        return (
            <div style={{display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center'}}>
                <div style={{display: 'flex', flexDirection: 'row',  alignItems: 'center'}}>
                    <h1>Widget List</h1>
                    <Button variant="contained" style={{ margin: 8, height: 40, backgroundColor: '#313132ff'}} onClick={() => this.togglePopup()}>Add New Widget</Button>
                </div>
                <div>
                    <DragDropContext onDragEnd={this.handleOnDragEnd}>
                        <Droppable droppableId="widgets">
                            {(provided) => (
                                <ImageList {...provided.droppableProps} ref={provided.innerRef} style={{width: Math.floor(window.innerWidth / 374) * 374}}>
                                    {this.state.widgets.map((widget, index) => {
                                        return (
                                            <Draggable key={index} draggableId={index.toString()} index={index}>
                                                {(provided) => (
                                                    <ImageListItem {...provided.draggableProps} {...provided.dragHandleProps} ref={provided.innerRef}>
                                                        <Widget loadWidgets={() => this.loadWidgets()} widget={widget} token={this.props.token} handleEdit={(widget, token) => this.handleEdit(widget, token)} handleDelete={(widget, token) => {this.handleDelete(widget, token)}}/>
                                                    </ImageListItem>)}
                                            </Draggable>
                                    )})}
                                    {provided.placeholder}
                                </ImageList>
                            )}
                        </Droppable>
                    </DragDropContext>
                    {this.state.isPopupOpen &&
                    <NewWidgetPopup handleClose={() => this.togglePopup()} addWidget={(service, widget, inputList) => this.addWidget(service, widget, inputList)} services={this.state.about.server}/>}
                </div>
            </div>
        );
    }

}

export default WidgetList;