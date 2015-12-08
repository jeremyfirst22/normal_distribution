#ifndef __IOFUNCTIONS_INCLUDED__
#define __IOFUNCTIONS_INCLUDED__

#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include "histogram.h" 

using namespace std ; 

/*
 Input: A 2-D vector of doubles, string holding filename to print to.
 Purpose: Prints the contents of a 2-D vector to a file.
 Assumptions: The file with filename will be overwritten. File will be printed in text.
 Output: Void, a file with input filename will be created (or overwritten) with the contents of the input 2-D vector.
 */
void print(vector< vector<double> >, string) ;


/*
 Input: A 2-D vector of doubles, string that hold a filename, the standard deviation(double), the average(double).
 Purpose: Calculates a quick and dirty gaussian estimation of a 2-D vector, and prints it to a
 supplied file name.
 Assumptions: That the input vector is a histogram with already calculated average
 and standard deviation.
 TODO: The height of the gaussian is assumed to be the maximum of the histogram.
 This is poor estimation and causes a continual overestimation of the gaussian.
 This function need to be more generalizable.
 Output: void, a file with input filename will be created (or overwritten) and the gaussian
 estimation of the input vector will be written to its contents.
 */
void print_gauss(vector< vector<double> >, string, double, double) ;


/*
 Input: filename (string)
 Purpose: Check to see if the file already exists. It is does, throw error message and quit.
 Assumptions: This function should only be called in the --overwrite flag is not given.
 Output: void. If the file does not exist, the program will quit.
 */
void checkFile(string) ;

#endif /* iofunctions_hpp */
