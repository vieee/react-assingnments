import React from 'react';
import './Box.css' 


const Box = (props) => {
    return (
        <div>
            <p>Hello { props.name }, you're just { props.age }</p>
        </div>
    )
};

export default Box;
