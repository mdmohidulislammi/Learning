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
            