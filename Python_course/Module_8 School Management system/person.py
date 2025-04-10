import random
from school import School
class Person:
    def __init__(self, name)-> None:
        self.name=name
        
class Teacher(Person):
    def __init__(self, name):
        super().__init__(name)
        
    def evaluate_exam(self):
        return random.randint(1,100)
    
class Student(Person):
    def __init__(self, name, classroom):
        super().__init__(name)
        self.classroom=classroom
        self.__id=None
        self.marks={} # {"math": 100}
        self.subject_grade={} # {"eng": 'A', "math": 'A+'}
        self.grade=None # final grade
    def final_grade(self):
        sum=0
        for grade in self.subject_grade.values():
            point= School.grade_to_value(grade) #5.0
            sum+=point
        if sum==0:
            gpa=0.00
            self.grade='F'
        else:
            gpa=sum/len(self.subject_grade) #9/2 =4.5
            self.grade=School.value_to_grade(gpa)
        print(f"{self.name} Final Grade : {self.grade} with GPA {gpa}")
    
    @property
    def id(self):
        return self.__id
    @id.setter
    def id(self, value):
        self.__id =value