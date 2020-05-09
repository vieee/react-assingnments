import React from 'react';
import CharComponent from './CharComponent/CharComponent';

const CharList = (props) => {
    return props.context.split('').map((vart, index) => {
        return (
            <CharComponent 
                name={vart}
                key={index}
                clicker={props.DeleteVarHandler.bind(this, index)} />
        );});
}

export default CharList;