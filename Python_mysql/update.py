import mysql.connector
db_name="python_test_db"
mydbconnection = mysql.connector.connect(
    host ="localhost",
    user ="root",
    passwd="password",
    database=db_name
)

mycursor = mydbconnection.cursor()
sqlquery="""
            UPDATE Student
            SET Name ='Mohidul'
            WHERE Name = 'Md. Mohidul Islam'"""
mycursor.execute(sqlquery)
mydbconnection.commit()
print("Update into table")
x=10
y=2
print(x//y)