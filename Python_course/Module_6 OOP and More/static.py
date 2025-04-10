class Shopping:
    cart = []  # class attribute or static attribute
    origin = 'China'

    def __init__(self, name, location) -> None:
        self.name = 'Jamu na city'  # instance attribute
        self.location = location

    def purchase(self, item, price, amount):
        remaining = amount-price
        print(f'buying: {item}, for price :{price} and remaining: {remaining}')

    @staticmethod
    def multiplying(a, b):
        result =a*b
        print(result)

    @classmethod
    def hudai_dekhi(self, item):
        print('hudai dekhi kntu kinmu just ac er hawa khaite ashci', item)


basundhara = Shopping("Basun dhara, not popular location", 'Not popular place')
basundhara.purchase('lungi', 500, 1000)
Shopping.purchase('Dokan', 'chocolate', 3, 8)
Shopping.hudai_dekhi('Lungi')
Shopping.multiplying(10, 20)