from matplotlib import pyplot as plt
x=[300,290,260,250]
y=[1010,1030,1050,1090]
plt.plot(x,y)
plt.title("Info")
plt.ylabel("Motor Speed, N (rpm)")
plt.xlabel("Field Current ,If (mA)")
plt.show()