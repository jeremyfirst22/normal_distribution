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

void fit_polynomial(vector<vector< double> >, double, int, string) ; 

#endif
