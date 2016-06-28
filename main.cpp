#include "option_parse.h"
#include "iofunctions.h"
#include "histogram.h"
#include <iostream> 
#include "objects.h"
#include "fit_polynomial.h"

int main(int argc, char** argv)
{
    //the options struct holds all run-time options. 
    options opt; 
    opt.overwrite = false ; 
    opt.gaussBool = false ; //Initialize --overwrite flag to false. Probably should handle 
                                //this in read_options. 
    opt.polyFit = false ; 

    vector<double> data ; 
    double avg, std ; 
    vector <vector<double> > hist ; 

    read_options(argc, argv, opt) ; 

    //Print run-time parameters
    cout << "inFile : " << opt.inFile << endl ; 
    cout << "outFile: " << opt.outFile << endl ; 
    cout << "numBins: " << opt.numBins << endl ; 
    cout << "overwrite : " ; 
    if (opt.overwrite) { cout << "True" << endl ; }
    else { cout << "False" << endl; }
    if ( opt.gaussBool ) {
        cout << "Gaussian fit file : " << opt.gaussFile << endl; 
    }
    if ( opt.polyFit ) {
        cout << "Polynomial fit file : " << opt.polyfitFile << endl; 
        cout << "Number of terms : " << opt.numTerms << endl ; 
    }

    //Begin program
    
    data = read_data(opt.inFile)  ; 

    cout << endl; 
    avg = average(data) ; 
    cout << "average = " << avg << endl; 

    std = stdDev(data,avg) ; 
    cout << "std     = " << std << endl ; 

    hist = histogram(data, opt.numBins) ; 
    print(hist,opt.outFile); 
    if (opt.gaussBool) 
        print_gauss(hist, opt.gaussFile, std, avg) ; 
    if (opt.polyFit) 
        fit_polynomial(hist,avg, opt.numTerms, opt.polyfitFile) ; 
    return 0; 
}

