class Laptop:
    def __init__(self, brand, price, color, memory) -> None:
        self.brand=brand
        self.price=price
        self.color=color
        self.memory=memory
    def run(self):
        return f'Running laprop: {self.brand}'
    def coding(self):
        return f'learning python and practicing'
class phone:
    def __init__(self, brand, price, color, dual_sim) -> None:
        self.brand=brand
        self.price=price
        self.color=color
        self.dual_sim=dual_sim
    def run(self):
        return f'Phone sharadin tipi.'
    def phone_call(self, number, text):
        return f'Sending sms to : {number}, with : {text}'
    
class Camera:
    def __init__(self, pixel, lens)-> None:
        self.pixel=pixel
        self.lens=lens
print('Hello world')