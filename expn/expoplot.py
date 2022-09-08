import matplotlib.pyplot as plt
import numpy as np
a=-25.14346
b=6.73966
x,y,yfit=np.loadtxt('outexp.txt',usecols=(0,1,3),unpack='True')
x1=np.linspace(0.0,0.2,50)
y1=np.exp(b+a*x1)
plt.xlabel('x')
plt.ylabel('y')
plt.title("Exponential-fit")
plt.plot(x,y,'r*')
plt.plot(x1,y1,'b-')
plt.legend(["y","yfit"])
#plt.show()
plt.savefig("expfit.pdf")
