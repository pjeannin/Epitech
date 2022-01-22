import * as React from 'react';
import {Button, IconButton, Slider, TextField} from "@mui/material";
import CloseIcon from "@mui/icons-material/Close";
import "../CSS/NewWidgetPopup.css";

const EditWidgetPopup = props => {

    let widget = props.widget;


    const handleUpdate = () => {
        props.sendEdit(widget, props.token);
        props.close();
    };


    return (
        <div className="popup-box">
            <div className="box">
                <div className="row">
                    <div>
                        <IconButton className="close-button" onClick={props.close}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <h2>Edit widget</h2>
                    <div/>
                </div>
                <div style={{marginTop: 25}}>
                    {widget.widgetData.params.map((param, index) => {
                        function valuetext(value) {
                            return `${value} seconds`;
                        }

                        if (param.name === 'Refresh time') {
                            return (
                                <div>
                                    <p>Refresh Time</p>
                                    <Slider
                                        onChange={(event, value) => widget.widgetData.params[index].data = value}
                                        key={index}
                                        aria-label="Refresh time"
                                        defaultValue={30}
                                        getAriaValueText={valuetext}
                                        valueLabelDisplay="auto"
                                        step={10}
                                        marks
                                        min={10}
                                        max={120}
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
                                onChange={(event) => {
                                    widget.widgetData.params[index].data = event.target.value
                                }}/>
                        )
                    })}
                    <div style={{display: 'flex', paddingRight: 20}}>
                        <Button style={{marginTop: 25, marginLeft: 'auto'}} variant="contained" color="primary" onClick={handleUpdate}>Update Widget</Button>
                    </div>
                </div>
            </div>
        </div>
    );
}

export default EditWidgetPopup;