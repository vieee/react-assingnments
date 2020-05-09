import React from 'react';
import './UserOutput.css';

const UserOutput = ( props ) => {

    let parLength = null;
    if ( props.length < 5) {
        parLength = (
            <p>
                Length too short..
            </p>
        );
    }
    else {
        if ( props.length > 18) {
            parLength = (
                <p>
                    Length too long..
                </p>
            );
        }
        else {
            parLength = (
                <p>
                    Good Password!
                </p>
            );
        }
    }

        return (
            <div className="UserOutput">
                <p>This length is, { props.length }</p>
                { parLength }
            </div>
        ) 
}

export default UserOutput;