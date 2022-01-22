import * as React from 'react';
import {useLocation} from "react-router-dom";
import axios from "axios";
import {withRouter} from "react-router-dom";
const config = require('../json/config.json')

const AuthRedditCallback = props => {
    const search = useLocation().search;
    const {history} = props;
    const code = new URLSearchParams(search).get('code');

    axios.post(`${config.expressIP}/api/user/redditToken`, {
        code: code,
        username: localStorage.getItem('username')
    }).then(res => {
        localStorage.setItem('reddit', 'true');
        history.push('/');
    }).catch(err => {
        console.log(err);
        history.push('/auth/redditFail');
    });

  return (
    <div>
      <h1>Reddit Connection</h1>
      <p>Linking RedditAccount</p>
    </div>
  );
};

export default withRouter(AuthRedditCallback);