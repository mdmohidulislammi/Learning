
function UserGreeting(props){
    if (props.isLoggedIn){
        return (<h2>Welcome {props.username}</h2>)

    }
    else
    {
        return <h1>You're not logged in </h1>
    }
}
export default UserGreeting