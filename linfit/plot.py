import matplotlib.pyplot as plt
import numpy as np
x,y,yfit=np.loadtxt('out.txt',usecols=(0,1,2),unpack='True')
plt.scatter(x,y)
plt.plot(x,yfit)
plt.show()

