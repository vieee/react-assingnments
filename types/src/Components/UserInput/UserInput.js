import React from 'react';
import './UserInput.css';

const UserInput = ( props ) => {
        return (
            <div className="UserInput">
                <h1>{ props.title }</h1>
                <input type="text" onChange={ props.changer } value={ props.value }/>
            </div>
        ) 
}

export default UserInput;