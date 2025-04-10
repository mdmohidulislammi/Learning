class Bank:
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
