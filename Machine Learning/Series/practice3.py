import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression


dataset=pd.read_csv('salary.csv')
x=dataset.iloc[:, :-1].values #first column
y=dataset.iloc[:, 1] #last column

x_train,x_test,y_train,y_test=train_test_split(x,y, test_size=1/3, random_state=0)

regressor=LinearRegression()
regressor.fit(x_train, y_train)

train=plt
train.scatter(x_train, y_train, color='green')
train.plot(x_train, regressor.predict(x_train), color='blue')
train.title("Salary VS Experience (Training Set)")
train.ylabel("Salary")
train.show()

test=plt
test.scatter(x_test, y_test, color='green')
test.plot(x_train, regressor.predict(x_train), color='blue')
test.title("Salary VS Experience (Test Set)")
test.xlabel("Year of Experience")
test.ylabel("Salary")
test.show()
y_pred=regressor.predict(np.array([[5]]))
print(y_pred)