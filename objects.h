#ifndef __OBJECTS_INCLUDED__
#define __OBJECTS_INCLUDED__

#include <string> 

using namespace std; 

//This struct holds the various program options accessible to the user. 
struct options{
    int numBins ;       //The number of bins to divide the data into. 
    string inFile ;     //A string holding the name of the file to read data from. 
                            //This data must be a single column of data. 
    string outFile ;    //A string holding the name of the file to write to.  
    string gaussFile ;  //A string holding thename of the file to write the Gaussian estimation. 
    string polyfitFile ; 

    bool overwrite ;    //A manual overwrite flag to overwrite files already present. 
    bool gaussBool ;    //A flag to estimate the histogram with a Gaussian. Switched on 
                            // when the -g option is given. 
    bool polyFit ; 
    int numTerms ; 
}; 

#endif
