#ifndef __OPTION_PARSE_INCLUDED__
#define __OPTION_PARSE_INCLUDED__

#include <iostream> 
#include <fstream> 
#include <boost/program_options.hpp> 
#include <string> 
#include "objects.h"
#include "iofunctions.h" 

using namespace std ; 
/*
Input: None. 
Purpose: Prints a description of the program to stdout. 
Assumptions: That stdout is a good pipe. Calls example() below. 
Output: Returns void, but prints description. 
*/
void description(); 

/*
Input: None. 
Purpose: Prints an example of how to use the program. 
Assumptions: That stdout is a good pipe. This function only called by description(). 
Output: Returns a void, but prints an example. 
*/
void example();  


/*
Input: The user input line from the command line.
Purpose: Read the command line options, and assigns these options to the struct options.
Assumptions: the struct options already exists. The Boost libraries are installed, and that the 
    boost_program_options library is linked. 
Output: Returns the struct options with the values changed to match the user input options. 
*/
int read_options(int, char**, options& ); 


#endif 
