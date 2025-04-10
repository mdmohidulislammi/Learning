class School:
    def __init__(self, name, address) -> None:
        self.name=name
        self.address=address
        self.teachers={} # {"Bangla" : teacher object}
        self.classrooms={}#{"Eight": classroom}
    def add_classroom(self, classroom):
        self.classrooms[classroom.name] =classroom
    def add_teacher(self, subject, teacher):
        self.teachers[subject]= teacher # subject.name die rakhte parbo   
    def student_admission(self, student):
        classname=student.classroom.name
        self.classrooms[classname].add_student(student)
    @staticmethod # this is method only use own class, not use another class
    def calculate_grade(marks):
        if marks>=80 and marks<=100:
            return 'A+'
        elif marks>=70 and marks <80:
            return 'A'
        elif marks >= 60 and marks <70:
            return 'A-'
        elif marks >=50 and marks< 60:
            return 'B'
        elif marks >=40 and marks< 50:
            return 'C'
        elif marks >=33 and marks< 40:
            return 'D'
        else :
            return 'F'
        
    @staticmethod
    def grade_to_value(grade):
        Grade={
            'A+': 5.00, 'A': 4.00, 'A-': 3.50, 'B': 3.00, 'C': 2.00, 'D': 1.00, 'F': 0.00
        }
        return Grade[grade]
    @staticmethod
    def value_to_grade(value):
        if  value ==5.00:
            return 'A+'
        elif value >=4.00 and value<5.00:
            return 'A'
        elif value >=3.50 and value <4.00:
            return 'A-'
        elif value >=3.00 and value< 3.50:
            return 'B'
        elif value >=2.00 and value <3.00:
            return 'C'
        elif value >= 1.00 and value <2.00:
            return 'D'
        else :
            return 'F'
    def __repr__(self):
        for key in self.classrooms.keys():
            print(key)
        print("\n---------------------------------------All Students-----------------------------------")
        result=''
        for key, value in self.classrooms.items():
            result+=f"-------{key.upper()}  Classroom Students ----------\n"
            for student in value.students:
                result+= f"{student.name}\n"
        print(result)
        subject=''
        for key, value in self.classrooms.items():
            subject+=f"-------{key.upper()} Classroom Subjects\n"
            for subj in value.subjects:
                subject+=f"{subj.name}\n"
        print(subject)
        #all teachers
        #all student result
        print("--------------------------Students Result----------------------------")
        for key, value in self.classrooms.items():
            for student in value.students:
                for k, i in student.marks.items():
                    print(student.name, k, i , student.subject_grade[k])
                print(student.final_grade())
        return  ''  
    
        