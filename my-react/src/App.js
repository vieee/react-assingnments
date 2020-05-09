import React, { Component } from 'react';
import './App.css';
import Box from './Box/Box'

class App extends Component {

  state = {
    persons : [
      { name: "Deeapk", age: 18 },
      { name: "Pamod", age: 13}
    ]
  }

  response = () = {
    this.setState({
      persons : [
        { name: "Deepaak", age: 19 },
        { name: "Pamod", age: 13}
      ]
    })
  }

  render() {
    return (
      <div className="App">
        <h1>This is an app...</h1>
        <button onClick = "this.response">
          Responses
        </button>
        <Box name={this.state.persons[0].name} age = {this.state.persons[0].age} />
        <Box name={this.state.persons[0].name} age = {this.state.persons[0].age} />        

      </div>
    );
  };
}

export default App;
