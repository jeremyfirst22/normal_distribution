#!/usr/bin/env python 

import matplotlib.pyplot as plt 
import numpy as np 
from matplotlib import rc_file 

import sys 
import os.path

def Usage(): 
    print "Usage %s < file to be plotted > [additional file(s)]" %(sys.argv[0]) 

if len(sys.argv) == 1 : 
    Usage() 
    print "ERROR: You must supply at least one file name" 
    sys.exit() 

for arg in sys.argv[1:] : 
    try : 
        fileName = arg
        data = np.genfromtxt(fileName) 
    except : 
        Usage() 
        print "ERROR:  file not able to be opened." 
        sys.exit() 
    
    outName = os.path.splitext(fileName)[0]+".pdf"
    print "%s => %s" %(fileName, outName) 
    
    rc_file("paper.rc") 
    
    plt.plot(data[:,0],data[:,1]) 
    plt.savefig(outName,format="pdf") 
