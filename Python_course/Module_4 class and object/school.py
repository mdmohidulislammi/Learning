class Student:
    def __init__(self, name, current_class, id):
        self.name = name
        self.id = id
        self.current_class = current_class

    def __repr__(self) -> str:
        return f'Student with name: {self.name}, class : {self.current_class}, id : {self.id}'


class Teacher:
    def __init__(self, name, subject, id) -> None:
        self.name = name
        self.subject = subject
        self.id = id

    def __repr__(self) -> str:
        return f'Teacher: {self.name}, subject: {self.subject}'


class schoool:
    def __init__(self, name, ) -> None:
        self.name = name
        self.teachers=[]
        self.students=[]

    def add_teacher(self, Name, subject):
        id = len(self.teachers)+100
        teacher = Teacher(Name, subject, id)
        self.teachers.append(teacher)
    
    def enroll(self, name, fee):
        if fee<6500:
            return 'Not enough fee for enrolling. '
        else:
            id=len(self.students) +1
            student=Student(name, 'C', id)
            self.students.append(student)
            return f'{name} is enrolled with id : {id}, extra money { fee- 6500}'
    def __repr__(self) -> str:
        print('___________________________Welcome to our school______________________________')
        print('___________________________Our Faculties_________________________')
        for teacher in self.teachers:
            print(teacher)
        print('---------------------------------Our All Students------------------------------')
        for student in self.students:
            print(student)
        return 'All done for now and then'


phitron=schoool('Phitron')
phitron.enroll('Alia', 5200)
phitron.enroll('Rani', 8000)
phitron.enroll('Mohidul', 10000)
phitron.enroll('Dj Baharul', 100000)
phitron.add_teacher('Dj Khairul', 'Algo')
phitron.add_teacher('Vaijan', 'DS')
phitron.add_teacher('Mak', 'Chemistry')
print(phitron)