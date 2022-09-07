import matplotlib.pyplot as plt
import numpy as np

x,y,yfit=np.loadtxt('outexp.txt',usecols=(0,1,3),unpack='True')
plt.xlabel('x')
plt.ylabel('y')
plt.title("Exponential-fit")
plt.scatter(x,y,marker='*',color='purple')
plt.plot(x,yfit)
plt.legend(["y","yfit"])
plt.show()
#plt.savefig("expfit.pdf")
