#ifndef __FUNCTIONS_INCLUDED__
#define __FUNCTIONS_INCLUDED__

#include <vector> 
#include <fstream> 
#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <cmath> 

using namespace std; 

vector<double> read_data(string) ; 

double minimum(vector<double>) ; 

double average(vector<double>) ; 

double stdDev(vector<double>,double) ; 

vector< vector<double> > histogram(vector<double>, int) ; 

void print(vector< vector<double> >, string) ; 

void print_gaussian(vector< vector< double > >, string , double, double) ; 

void checkFile(string, bool) ; 

#endif 
