#include "functions.h" 

vector<double> read_data(string fileName){
    ifstream f ; 
    vector<double> data ; 
    double value ; 
    f.open(fileName.c_str()) ; 
    if( f.is_open() ) 
    {
        while (f>>value) 
        {
            data.push_back(value); 
        }
    } 
    f.close(); 
    return data ; 
}

double minimum(vector<double>data)
{
    double min = data[0] ; 
    for (int i = 0 ; i < data.size() ; i++) 
    {
        if (data[i] < min ) {
            min = data[i] ; 
        }
    }
    return min ; 
}
double maximum(vector<double>data) 
{
    double max = data[0] ; 
    for (int i = 0; i < data.size() ; i++) 
    {
        if (data[i] > max ){
            max = data[i] ; 
        }
    }
    return max ; 
}

double average(vector<double> data) 
{
    double avg = 0 ; 
    for (int i = 0 ; i < data.size() ; i++)
    {
        avg+= data[i] ; 
    }
    avg=avg/data.size() ; 
    return avg ; 
}

double stdDev(vector<double> data, double mean)
{
    double std ; 
    vector<double> var ; 
    for (int i = 0 ; i < data.size() ; i++)
    {   
        var.push_back(pow(data[i] - mean,2)) ; 
    }
    std = pow(average(var),0.5) ; 
    
    return std ; 
}

vector<vector<double> >histogram(vector<double> data, int numBins)
{
    vector< vector<double> > histogram ; //2-D vector of histogram. 
    double min = minimum(data) ; 
    double max = maximum(data) ; 
    cout << data.size() << endl; 

    double binSize = (max - min)/double(numBins) ; 

    for( int i = 0 ; i < numBins ; i++) 
    {
        double bin = binSize*i + min + 0.5*binSize; 
        vector<double> row ; 
        row.push_back(bin) ; 
        row.push_back(0) ; 
        histogram.push_back(row) ;  
    }

    for (int i = 0 ; i < data.size() ; i++) 
    {
        for (int j = 0 ; j < histogram.size() ; j++)
        {
            double minBin = binSize*j+min ; 
            double maxBin = minBin+binSize ; 
            if ( minBin <= data[i] && data[i] < maxBin) 
            {
                histogram[j][1] += 1; 
            }
        }
        if (data[i] == max )
        {
            histogram.back()[1]+=1 ; 
        }
    }

    for (int i = 0 ; i < histogram.size() ; i++)
    {
        histogram[i][1] = histogram[i][1] / double(data.size()) ; 

    }

    return histogram ; 
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

void print_gaussian( vector< vector<double> > hist, string outFile, double std, double avg)   
{
    ofstream f;
    double x, gauss ;  
    f.open(outFile.c_str()) ; 
    if (! f.is_open()){
        cerr << "ERROR: Gaussian output file failed to open" << endl ; 
        exit(1) ; 
    }

    for (int i = 0 ; i < hist.size() ; i++) 
    {
        x = hist[i][0] ; 
        gauss = 2/(std*sqrt(2*3.1415)) * exp(-1* pow(x - avg,2)/(2*pow(std,2)) ) ; 
        cout << x << "    " << gauss << endl; 
    }

    
    f.close() ; 
}

void checkFile(string fileName, bool overwrite) {
    ifstream fileHandle ; 
    if (! overwrite) 
    {
        ifstream outHandle(fileName.c_str() ) ; 
        if(outHandle.good() ) 
        {
            cerr << "ERROR: " << fileName << " already exists. Use \"--overwrite\" flag to force overwrite of data" << endl ; 
            exit(1) ; 
        }
    }
    fileHandle.exceptions( ifstream::failbit | ifstream:: badbit) ; 
    try
    {   
        fileHandle.open(fileName.c_str()) ; 
        fileHandle.close() ; 
    }
    catch(ifstream::failure e) 
    {
        cerr << e.what()  << endl ; 
        cerr << "ERROR: " << fileName << " unable to be opened " << endl; 
        exit(1) ; 
    }
}
