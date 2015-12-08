import numpy as np
import math as m
from sys import exit

x = np.linspace(120,130)
y = np.exp(-pow(x - 125,2)/pow(2,2)) 

from matplotlib import rc_file
##rc_file('plot.rc')

import matplotlib.pyplot as plt

plt.plot(x,y)
plt.ylim([0,1])
plt.xlabel('Nitrile angle(degrees)') 
plt.ylabel('% of occurances') 

plt.savefig('plot.png') 
