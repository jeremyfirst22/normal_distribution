#ifndef __OBJECTS_INCLUDED__
#define __OBJECTS_INCLUDED__

#include <string> 

using namespace std; 

struct options{
    int numBins ; 
    string inFile ; 
    string outFile ; 
    string gaussFile ; 
    bool overwrite ; 
    bool gaussBool ; 
}; 

#endif
