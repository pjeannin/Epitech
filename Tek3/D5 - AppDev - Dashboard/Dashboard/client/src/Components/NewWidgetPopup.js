import React from "react";
import "../CSS/NewWidgetPopup.css";
import {FormControl, IconButton, InputLabel, MenuItem, Select, TextField, Button, Slider} from "@mui/material";
import CloseIcon from '@mui/icons-material/Close';

const NewWidgetPopup = props => {
    const [service, setService] = React.useState('');
    const [serviceIndex, setServiceIndex] = React.useState(0);
    const [widget, setWidget] = React.useState('');
    const [widgetIndex, setWidgetIndex] = React.useState(0);
    const [inputList, setInputList] = React.useState([{name: '', type: '', value: ''}]);

    const handleChangeService = (event) => {
        setService(event.target.value);
        setWidget('');
        setWidgetIndex(0);
    };

    const handleChangeWidget = (event) => {
        setWidget(event.target.value);
    };

    const handleIndexServices = (index) => {
        setServiceIndex(index);
    };

    const handleIndexWidgets = (index) => {
        setWidgetIndex(index);
        let list = [];
        for (let i = 0; i < props.services.services[serviceIndex].widgets[index].params.length; ++i) {
            list.push({value: '', type: props.services.services[serviceIndex].widgets[index].params[i].type, name: props.services.services[serviceIndex].widgets[index].params[i].name})
        }
        setInputList(list);
    };

    const handleChangeInput = (value, index) => {
        let list = [...inputList];
        list[index].value = value;
        setInputList(list);
    };

    const validateInput = () => {
        let list = [...inputList];
        for (let i = 0; i < list.length; ++i) {
            if (list[i].name === 'Refresh time') {
                if (list[i].value === '') {
                    list[i].value = '30';
                }
            }
            if (list[i].value === '') {
                return false;
            }
            if (list[i].type === 'number') {
                if (isNaN(list[i].value)) {
                    return false;
                }
            }
        }
        return true;
    };

    const handleAdd = () => {
        if (validateInput()) {
            let list = [];
            for (let i = 0; i < inputList.length; ++i) {
                list.push({name: inputList[i].name, data: inputList[i].value})
            }
            props.addWidget(service, widget, list);
            props.handleClose();

        } else {
            alert("All fields don't have right type");
        }
    }

    return (
        <div className="popup-box">
            <div className="box">
                <div className="row">
                    <div>
                        <IconButton className="close-button" onClick={props.handleClose}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <h2>Add a new Widget</h2>
                    <div/>
                    <div/>
                </div>
                <div>
                    <FormControl fullWidth>
                        <InputLabel key={-2} id="demo-simple-select-label">Service</InputLabel>
                        <Select
                            key={-3}
                            labelId="demo-simple-select-label"
                            id="demo-simple-select"
                            value={service}
                            label="Service"
                            onChange={handleChangeService}>
                            {props.services.services.map((service, index) => {
                                if (service.name === 'Reddit' && localStorage.getItem('reddit') === 'false') {
                                    return (
                                        <div key={index}/>
                                    )
                                }
                                return (
                                    <MenuItem key={index} value={service.name}
                                              onClick={() => handleIndexServices(index)}>{service.name}</MenuItem>
                                )
                            })}
                        </Select>
                    </FormControl>
                    {service !== '' && <FormControl key={-1} style={{marginTop: 20}} fullWidth>
                        <InputLabel key={-4} id="demo-simple-select-label">Widget</InputLabel>
                        <Select
                            key={-5}
                            labelId="demo-simple-select-label"
                            id="demo-simple-select"
                            value={widget}
                            label="Widget"
                            onChange={handleChangeWidget}>
                            {props.services.services[serviceIndex].widgets.map((widget, index) => (
                                <MenuItem key={index} value={widget.name} onClick={() => handleIndexWidgets(index)}>{widget.name}</MenuItem>
                            ))}
                        </Select>
                    </FormControl>}
                    {widget !== '' &&
                    <div style={{marginTop: 25}}>
                        {props.services.services[serviceIndex].widgets[widgetIndex].params.map((param, index) => {
                            function valuetext(value) {
                                return `${value} seconds`;
                            }

                            if (param.name === 'Refresh time' || param.name === 'Day number') {
                                return (
                                    <div key={index}>
                                        <p>{param.name}</p>
                                        <Slider
                                        onChange={(event, value) => handleChangeInput(value, index)}
                                        aria-label="Refresh time"
                                        defaultValue={param.name === 'Refresh time' ? 30 : 2}
                                        getAriaValueText={valuetext}
                                        valueLabelDisplay="auto"
                                        step={param.name === 'Refresh time' ? 10 : 1}
                                        marks
                                        min={param.name === 'Refresh time' ? 10 : 1}
                                        max={param.name === 'Refresh time' ? 120: 3}
                                        />
                                    </div>)
                            }
                            return (
                                <TextField
                                    style={{width: '100%'}}
                                    key={index}
                                    label={param.name}
                                    value={param.value}
                                    margin="normal"
                                    variant="outlined"
                                    onChange={(event) => handleChangeInput(event.target.value, index)}/>
                            )
                        })}
                        <div style={{display: 'flex', paddingRight: 20}}>
                            <Button style={{marginTop: 25, marginLeft: 'auto'}} variant="contained" color="primary" onClick={handleAdd}>Add Widget</Button>
                        </div>
                    </div>
                    }
                </div>
            </div>
        </div>
    );
};

export default NewWidgetPopup