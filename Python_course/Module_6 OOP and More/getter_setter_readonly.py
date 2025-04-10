class User:
    def __init__(self, name, age, money)-> None:
        self._name=name
        self._age=age
        self.__money=money
        
    @property # getter without any setter is readonly attribute 
    def age(self):
        return self._age
    @property # getter
    def salary(self):
        return self.__money
    #setter
    @salary.setter
    def salary(self, value):
        if value< 0:
            print('Salary can not be negative')
            
        self.__money+=value
        
samsu=User('Kopa', 21, 120000)
# print(samsu.__money)
# print(samsu.age())
print(samsu.age)
# print(samsu.salary())
samsu.salary=12000
print(samsu.salary)
#read only-> you can not set the value. Value can not be changed 
# getter --> get a value of a property through a mehtod . Most of the time, you will get the value of a private attribute.
# setter --> set a value of a property through a method. Most of the time, you will set the value of a private property.