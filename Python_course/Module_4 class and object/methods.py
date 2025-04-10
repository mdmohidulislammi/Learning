def call():
    print("Calling someone I don't know.")
    return 'call done'

class Phone:
    price =1200
    color='blue'
    brand='Samsung'
    features=['camera', 'speakers', 'hammer']

    def call(sekf): # can use different name but self is giving for our benefits 
        print('Calling one person')
    def send_sms(phone, sms):
        text=f'sending SMS to: {phone} and message: {sms}'
        return text

my_phone=Phone()
print(my_phone.features)
my_phone.call()