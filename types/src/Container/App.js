import './App.css';
import UserInput from '../Components/UserInput/UserInput';
import UserOutput from '../Components/UserOutput/UserOutput';
import CharList from '../Components/CharLIst/CharList';
import React, { Component } from 'react'


class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      context: '',
    };
  }
  

  DeleteContentHandler = ( index ) => {
    const personList = [...this.state.name];
    personList.splice(index, 1);
    this.setState({
      name: personList,
    })
  }


  NameChangeHandler = ( event ) => {
    this.setState({
      context: event.target.value,
    })
  }

  DisplayPeopleHandler = () => {
    const display = this.state.repeater;
    this.setState({
      repeater: !display,
    }) 
  }

  DeleteVarHandler = ( index ) => {
    const person = this.state.context.split("");
    person.splice(index, 1);
    const updatedText = person.join("");
    this.setState({
      context: updatedText,
    })
  }

  style = {
    color: 'black',
    boxShadow: '5px 10px #888888'

  }

  render() {

    return (
      <div className="App">
          <UserInput title={ this.props.title } value={ this.state.context } changer={ this.NameChangeHandler } />
          <hr style={ this.style } />
          <UserOutput length= { this.state.context.length } />
          <CharList context={ this.state.context } DeleteVarHandler={ this.DeleteVarHandler }/>
      </div>
    )
  }
}

export default App;
