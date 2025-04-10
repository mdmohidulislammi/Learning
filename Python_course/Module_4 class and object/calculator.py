class calculator:
    brand= 'Casio cw991'
    def add (self, num1, num2):
        return num1+num2
    def mul(self, num1, num2):
        return num1*num2
    def div(self, num1, num2):
        return num1/num2
    
calculation=calculator()
print(calculation.brand)
print(calculation.add(1,2))
print(calculation.mul(38, 50))
print(calculation.div(50, 100))