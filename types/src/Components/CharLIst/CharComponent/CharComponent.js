import React from 'react';
import './CharComponent.css';

const CharComponent = ( props ) => {

    return (
        <div className="CharComponent">
            { props.name }
            <br />
            <button onClick={ props.clicker }>Remove Me!</button>
        </div>
    )
}

export default CharComponent;
