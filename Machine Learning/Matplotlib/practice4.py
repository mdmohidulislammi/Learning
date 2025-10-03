from matplotlib import pyplot as plt 
age =[22,55,62,45,2122,24,42,42,4,2,102,95,85,55,110,120]
bins=[0,10,20,30,40,50,60,70,80,90,100]
plt.hist(age,bins)
plt.xlabel("Age groups")
plt.ylabel("Number of people")
plt.title("Histogram")
plt.show()