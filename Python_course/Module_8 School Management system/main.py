from school import School
from person import Teacher, Student
from subject import Subject
from classroom import ClassRoom

school =School('ABC', "Dhaka")
eight =ClassRoom("Eight")
nine=ClassRoom("Nine")
ten =ClassRoom("Ten")
school.add_classroom(eight)
school.add_classroom(nine)
school.add_classroom(ten)

rahim=Student("Rahim", eight)
karim =Student("Karim", nine)
fahim=Student("Fahim", ten)
mohidul=Student("Mohidul", ten)

school.student_admission(rahim)
school.student_admission(karim)
school.student_admission(fahim)
school.student_admission(mohidul)

abul=Teacher("Abul Islam")
babul=Teacher("Babul Islam")
kabul=Teacher("Kabul Islam")

bangla=Subject("Bangla", abul)
english=Subject("English", babul)
chemistry=Subject("Chemistry", kabul)
biology=Subject("Biology", abul)


eight.add_subject(bangla)
eight.add_subject(english)

nine.add_subject(bangla)
nine.add_subject(english)
nine.add_subject(chemistry)
nine.add_subject(biology)

ten.add_subject(bangla)
ten.add_subject(english)
ten.add_subject(chemistry)
ten.add_subject(biology)

eight.take_semester_exam()
nine.take_semester_exam()
ten.take_semester_exam()

print(school)