#ifndef __OPTION_PARSE_INCLUDED__
#define __OPTION_PARSE_INCLUDED__

#include <iostream> 
#include <fstream> 
#include <boost/program_options.hpp> 
#include <string> 
#include "objects.h"
#include "functions.h"

using namespace std ; 

void description(); 
void example();  
int read_options(int, char**, options& ); 


#endif 
