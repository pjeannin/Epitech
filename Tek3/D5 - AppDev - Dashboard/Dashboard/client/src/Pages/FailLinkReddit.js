import * as React from 'react';
import {withRouter} from "react-router-dom";

const FailLinkReddit = props => {
    return (
        <div>
            <h1>Reddit Connection</h1>
            <p>Fail to link reddit account</p>
        </div>
    );
};

export default withRouter(FailLinkReddit);