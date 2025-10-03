class Bank:
<<<<<<< HEAD
    def __init__(self, holder_name, initial_deposit) -> None:
        self.holder_name=holder_name # public attribute
        self._branch='Uttara sector: 7' # protected
        self.__balance=initial_deposit # private
        
    def deposit(self, amount):
        self.__balance+=amount
        
    def get_balance(self):
        return  self.__balance
    
    def withdraw(self, amount):
        if amount< self.__balance:
            self.__balancce=self.__balance -amount
            return amount
        else:
            return f'Fokir taka nai.'
     
rafsun= Bank('chooto bro', 10000)
print(rafsun.holder_name)
rafsun.holder_name='booro vai'
# rafsun.balance=0
# print(rafsun.balance)
rafsun.deposit(10000)
print(rafsun.deposit)
print(rafsun.get_balance())
=======
    def __init__(self, customer, deposit):
        self.customer=customer
        self.__balance=deposit
    def get_balance(self):
        return self.__balance
    def increment(self, amount):
        self.__balance+=amount
        
    def decrement(self, amount):
        self.__balance-=amount
        print(self.get_balance())

mohidul=Bank('Md. Mohidul Islam', 12000)
# mohidul.decrement(200)
# print(mohidul.__balance)
print(mohidul.__balance)
print(mohidul._Bank__balance)
>>>>>>> f9ddbb6 (Adding new files after learning)
