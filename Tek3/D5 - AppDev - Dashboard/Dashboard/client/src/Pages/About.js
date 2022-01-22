import * as React from 'react';
import axios from "axios";
const config = require('../json/config.json')

class About extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            about: {}
        };
    }

    componentDidMount() {
        axios.get(`${config.expressIP}/about.json`)
            .then((response) => {
                this.setState({
                    about: response.data
                });
            })
            .catch(function (error) {
                console.log(error);
            });
    }

    render() {

        return (
            <div>
                <h1>About</h1>
                <div>
                    <pre>{JSON.stringify(this.state.about, null, 2)}</pre>
                </div>
            </div>
        );
    }
}

export default About;