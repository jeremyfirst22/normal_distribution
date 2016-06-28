#include "histogram.h" 

vector<double> read_data(string fileName){
    ifstream f ; 
    vector<double> data ; 
    double value ; 
    char line[128] ; 
    f.open(fileName.c_str()) ; 
    
    bool done = false ; 
    while (f.good()) {
        f.getline(line, 128) ; 
    
        if (strlen(line) == 0 ) continue  ; 
        else if (line[0] == '#' ) continue ; 
        else { 
            value =  atof(line ) ; 
            data.push_back(value) ; 
        } 
    }
    // Added ignoring of comments. only works for lines starting with '#' 
/*    if (f.is_open() ) 
    {
        while (f>>value) 
        {
            data.push_back(value); 
        }
    } 
*/    
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

double column_maximum(vector< vector<double> > data, int col)
{
    double max = data[0][col] ; 
    for (int i = 0 ; i < data.size() ; i++) 
    {
        if (data[i][col] > max ) {
            max = data[i][col] ; 
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
        }   //Adds the max value to last bin, making the final bin of the histogram inclusive. (min,max]. 
    }
    hist_normalize(histogram, binSize) ; 

    return histogram ; 
}

void normalize(vector< vector<double> >& data) 
{
    double mag = magnitude(data) ; //This is only the magnitude of the second column of the data. 
    for ( int i = 0 ; i < data.size() ; i ++) 
    {       
        data[i][1] = data[i][1] / mag ; //This only normalizes the second column of the data. 
    }
    return ;  
}

void hist_normalize(vector< vector<double> >& data, double binwidth) 
{
    double mag = magnitude(data) ; //This is only the magnitude of the second column of the data. 
    //cout << mag << endl; 
    for ( int i = 0 ; i < data.size() ; i ++) 
    {       
        data[i][1] = data[i][1] / (mag * binwidth) ; //This only normalizes the second column of the data. 
    }
    return ;  
}

double magnitude(vector <vector<double> > data) 
{
    double mag = 0 ; 
    for (int i = 0 ; i < data.size() ; i++) 
    {       
        mag += data[i][1] ; //This only calculates the magnitude of the second column of data. 
    }
    return mag ; 

}
