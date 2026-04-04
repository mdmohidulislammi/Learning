import PropTypes from "prop-types";
function Student({name, age, isStudent}){
return (
<div className="student">
    <p>Name: {name} age: {age} Student: {isStudent ? "Yes" : "No"}</p>
</div>
);
Student.propTypes={
    name: PropTypes.string,
    age: PropTypes.number,
    isStudent:PropTypes.bool,
}
Student.defaultProps={
    name:"mohidul", 
    age:29,
    isStudent:true
}
}
export default Student