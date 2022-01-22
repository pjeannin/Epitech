import * as React from 'react';

const ColoredLine = ({ color }) => (
    <hr
        style={{
            color: color,
            backgroundColor: color,
            height: 2,
            borderRadius: 2,
            marginLeft: 40,
            marginRight: 40,
        }}
    />
);

export default ColoredLine;