import random

name="Md. Mohidul Islam"
user="mdmohidulmmi"
psd="******"
while True:
    user_name=input("Enter User name: ")
    password=input("Enter the password: ")
    if (password==psd and user==user_name):
        otp=random.randint(100000, 999999)
        user_otp=int(input("Enter the otp : "))
        if otp==user_otp: 
            print(f"Ohh You loggd in. Welcome {name} to our system")
            break
        else:
            print("You have entered wrong otp.")


