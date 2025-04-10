class person:
    def __init__(self, name, age, height, weight)-> None:
        self.name=name
        self.age=age
        self.height=height
        self.weight=weight
        
    def eat(self):
        print('Vat mangsho polau korma')
    def exercise(self):
        raise NotImplementedError
class Cricketer(person):
    def __init__(self, name, age, height, weight, team)->None:
        self.team=team
        super().__init__(name, age, height, weight)
        
    def eat(self):
        print('Vegetables')
        
    def exercise(self):
        print("Gym a poisha diya jao")
    def __add__(self, other):
        return self.age+ other.age  # dunder method
        

Shakib=Cricketer('sakib', 23, 36, 29, 'BD')
print(Shakib.eat())

# python dunder method or magic method