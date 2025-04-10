#poly --> many 
# more--> shape
class Animal: 
    def __init__(self, name) -> None:
        self.name=name
        
    def make_sound(self):
        print("animal making some sound")
class Cat(Animal):
    def __init__(self, name):
        super().__init__(name)
    def make_sound(self):
        print('mewo mewo')  
        
class Dog(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)
        
    def make_sound(self):
        print("Gheu Gheu")
class Goat(Animal):
    def __init__(self, name):
        super().__init__(name)
 
don=Cat('Real Don')
don.make_sound()
Shphard=Dog('Local Shephard')
Shphard.make_sound()
mess=Goat('ab')
mess.make_sound()