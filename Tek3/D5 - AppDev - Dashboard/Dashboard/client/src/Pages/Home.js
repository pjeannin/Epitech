import * as React from 'react';
import WidgetList from "../Components/WidgetList";


const Home = props => {
    return (
        <div>
            <WidgetList token={props.token}/>
        </div>
    );
}

export default Home;