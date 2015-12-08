#ifndef __HISTOGRAM_INCLUDED__
#define __HISTOGRAM_INCLUDED__

#include <vector> 
#include <fstream> 
#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <cmath> 

using namespace std; 

/*
Input: String of a filename to read from. 
Purpose: Reads the data from a supplied file name and 
  returns a vector of all data. 
Assumptions: Assumes that the file contains only the data, no header or footer. 
  Also assumes that the data is one dimensional. 
Output: Returns a vector of doubles containing the data.
*/
vector<double> read_data(string) ; 


/*
Input: A vector of doubles. 
Purpose: Find the minimum element. 
Assumptions: That the vector is of type double. 
Output: Returns a double, the minimum of the vector
*/
double minimum(vector<double>) ; 


/*
Input: A vector of doubles. 
Purpose: Find the maximum element. 
Assumptions: That the vector is of type double. 
Output: Returns a double, the maximum of the vector
*/
double maximum(vector<double>) ; 

/*
Input: A 2-D vector of doubles, and the column (i) of which you wish to find a maximum. 
Purpose: Find the maximum of either column of a 2-D vector. 
Assumptions: Both vectors are of equal length and are of type double. 
Output: Returns a double, the maximum of column i. 
*/
double column_maximum(vector< vector<double> >, int) ; 

/*
Input: A vector of all doubles. 
Purpose: Calculate the average of all the elements in the double. 
Assumptions: That the elements are not so large that their sum will overflow a double. 
Output: Returns a double, the average of the elements. 
*/
double average(vector<double>) ; 

/*
Input: A vector of doubles , and the average of the vector. 
    Meant to be used after the average function above. 
Purpose: Calculate the standard deviation of the elements of a vector. 
    In the background, this function calculates a vector of the variance of each element. 
Assumptions: That the average has already been calculated.
Output: Returns a double, the standard deviation of the vector. 
*/
double stdDev(vector<double>,double) ; 

/*
Input: A 1-D vector of data, and the number of bins in which to bin the elements of the vector. 
Purpose: Calculate a histogram of data using a user specified number of bins. 
Assumptions: The number of bins is divided evenly between the minimum and maximum of the data. 
    The histogram is normalized to 1. 
    The maximum of the data, which falls on the boundary of the last bin, is added to the last bin.     That the data and number of bins is sufficiently slow for this operation to happen. 
        i.e., 100000 data points into 10000 bins takes 8.230s. 
Output: A 2-D vector. The first column contains the middle of the bin. The second column contains 
    the percentage of occurance in the data vector. 
*/
vector< vector<double> > histogram(vector<double>, int) ; 

/*
Input: A 2-D vector of data PASSED BY ADDRESS. 
Purpose: Normalize the last column of the vector to 1, by dividing by the magnitude of the vector. 
Assumptions: That the last column of the vector is what needs to be normalized. 
    That the vector is to be normalized to 1. 
    TODO: This functions needs to be made more universal, and not a reference pass! It is dangerous as is. 
Output: void. Input function is modified in memory, and does not need to be caputured. 
*/
void normalize(vector<vector<double> >&) ; 

void hist_normalize(vector<vector<double> >&, double) ; 


/*
Input: A 2-D vector of double. 
Purpose: Calculate the magnitude of the SECOND column of the vector. 
Assumputions: Only calculates the magnitude of the second column. 
    Assumes that the magnitude of the vector is small enough to not overflow a double. 
    TODO: This function also needs to be generalized. Not being able to the specify
       which column to use is dumb. 
Output: A double, the magnitude of the second column of the vector. 
*/
double magnitude(vector <vector <double> >) ; 

#endif 
