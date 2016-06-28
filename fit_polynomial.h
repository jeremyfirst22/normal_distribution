#ifndef __FIT_POLYNOMIAL_INCLUDED__
#define __FIT_POLYNOMIAL_INCLUDED__

#include <iostream> 
#include <vector> 
#include <cmath> 
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_multifit.h>
#include <fstream> 
#include <string> 
#include "iofunctions.h"

using namespace std ; 


/*
Input: A 2-D vector of doubles (histogram), a double that is the mean value of the data (around which to center the polynomial, and a integer that is the number of terms in the expansion, a string holding the filename to print to.
Purpose: Fit a Taylor exansion polynomial to the histogram. 
Assumptions: That the mean is the most important part to fit. The function is smooth. 
Output: Calls the print function and prints the polynomial fit to a file. 
TODO: From the Taylor series, we should be able to back calculate a double gaussian? 
    Need to do the math to figure this out. 
*/
void fit_polynomial(vector<vector< double> >, double, int, string) ; 

#endif
