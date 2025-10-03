<<<<<<< HEAD
class Bank:
    def __init__(self, balance):
        self.balance=balance
        self.minwithdraw=100
        self.mzxwithdraw=100000
    def get_balance(self):
        return self.balance
    def deposite(self, amount):
        if amount>0:
            self.balance+=amount
    def withdraw(self, amount):
        if amount< self.minwithdraw:
            print('You can\'t withdraw your balance . Because you are a fokir')
        elif amount > self.mzxwithdraw:
            print('Your bank get fokir and you also shokir')
        else:
            self.balance-=amount
            print(f'Here is your money {amount}')
            print(f'Your balance after withdraw :{self.get_balance()}')

brac=Bank(15000)
brac.withdraw(25)
brac.withdraw(25000000)
brac.withdraw(10000)
            
=======
class Bank: 
    def __init__(self, balance):
        self.balance=balance
        self.min_with=200
        self.max_with=1000000
    def show_balance(self):
        return self.balance
    def deposite(self, amount):
        self.balance+=amount
        return self.balance
    def withdraw(self, amount):
        if(amount>self.balance+self.min_with):
            print("You have insufficient balance. Please try again")
            return self.balance
        elif(amount<self.min_with):
            print("You can not withdraw this little amount. Please try again...")
            return self.balance
        elif(amount>self.max_with):
            print("You cross the limit. Please try again...")
            return  self.balance
        else:
            self.balance-=amount
            print(f'Withdraw successful. Here is your current balance {self.balance}')
            return "Thanks for reaching us."
    
Brac=Bank(15000)
Brac.deposite(15000)
print(Brac.withdraw(100000))
print(Brac.balance)
>>>>>>> f9ddbb6 (Adding new files after learning)
