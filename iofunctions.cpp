#include "iofunctions.h"

using namespace std ; 

void checkFile(string fileName)
{
    ifstream f(fileName.c_str()) ;
    if (f.good()) //This will flag if the file already exists. It is only called if the --overwrite flag is not given.
    {
        cerr << "ERROR: " << fileName << " already exits.\n\t If you wish to overwrite this file, use the \"--overwrite\" flag with caution." << endl ;
        exit(1) ;
    }
}

void print_gauss(vector <vector <double > > hist, string outFile, double std, double avg)
{
    ofstream f ;
    f.open(outFile.c_str()) ;
    double x, gauss ;
    
    double a = column_maximum(hist, 1) ;
    //cout << a << endl ;
    for (int i = 0 ; i < hist.size() ; i++)
    {
        x = hist[i][0] ;
        
        gauss = 1/(std * sqrt(2 * M_PI) ) *exp(-(pow((x - avg),2))/(2*pow(std,2)))  ;
        //
        //              -(x-mu)^2 / ( 2 sigma^2)
        //  y = a * exp^
        //
        //
        f << x << "\t" << gauss << endl;
    }
    f.close() ;
}

void print(vector< vector<double> > hist, string outFile)
{
    ofstream f ;
    f.open(outFile.c_str()) ;
    if (! f.is_open()){
        cerr << "ERROR: Output file failed to open" << endl;
        exit(1);
    }
    
    for (int i = 0 ; i < hist.size() ; i++)
    {
        f <<  hist[i][0] << "\t" << hist[i][1] << endl;
    }
    f.close() ;
}

