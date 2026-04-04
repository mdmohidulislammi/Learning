
import './App.css'
import Student from './student.jsx'
import UserGreeting from './UserGreeting.jsx'
import List from './list.jsx'
import Counter from './counter.jsx'

function App() {
  const fruits=[{id:1, name:"apple", calories:90},
    {id:2, name:"pineapple", calories:127},
    {id:3 , name:"coconut", calories:102}, 
    {id:4, name:"banana", caloris:130}
  ]
  const vegetables=[{id:1, name:"potatoes", calories:110},
                    {
                      id:2, name:"carot", calories:60
                    },
                    {id:3, name : "corn", calories:50}
  ]
  return (
    <>
    <Student name="Mohidul"
    age={20} isStudent ={true}
    />
    <Student name="Nahidul"
    age={19} isStudent ={false}
    />
    <Student name="Mohidul"
    age={15} isStudent ={true}
    />
    <UserGreeting isLoggedIn={true} username="Mohidul"/>
    <List items={fruits} category="Fruits" />
    <List items={vegetables} category="Vegetables" />
     <Counter/>
    </>
  )
}

export default App
