This program returns the normal distribution of data from a file. It will calculate:
    1) A histogram of occurances, using a user-specified number of bins. 
    2) The mean and standard deviation of all data. 
    3) The most probable value (highest occupied bin of histogram)
    4) An estimated gaussian fit of the histogram (with the -g option) 

Before you install, ensure that the boost libraries are installed and available on your machine. 

Install:
    Open Terminal. 
    Type "tar xvfz /path/to/tiltAngle/directory" and hit Enter. 
    Type "cd tiltAngle" and hit Enter. 
    Type "make" and hit Enter. Let me know if any errors appear.

It has only been tested on the gcc compiler. 
Included is a Makefile for easy installation. 
To check if you have "make", type "which make" on the command line. If a path to a file called "make" appears, you have it!

Type "./tiltAngle --help" to display command line options and information. 

Example invocation: ./tiltAngle -f nitrileangles.dat -o angle_distribution.txt -n 100 
    ## This creates a distribution of data from 'nitrileangles.dat', 
    ##      and writes a histogram of the data to 'angle_distribution.txt'. 
    ##      The histogram is generated with 100 bins, evenly spaced between 
    ##      the minimum and maximum value found in 'nitrileangles.dat'. 
