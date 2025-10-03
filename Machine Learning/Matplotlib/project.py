from matplotlib import pyplot as plt
x =[]
y=[]
title_name=input("Give the title of the Graph : ")
x_title=input("Give the title of the x axis :")
y_title=input("Give the y axis title : ")
while(True):
    x_value=float(input("Enter x value : "))
    if x_value != -99:
       x.append(x_value)
    else:
        break
while(True):
    y_value=float(input("Enter y axis value : "))
    if y_value!= -99:
        y.append(y_value)
    else:
        break


plt.plot(x,y)
plt.title(title_name)
plt.xlabel(x_title)
plt.ylabel(y_title)
plt.show()