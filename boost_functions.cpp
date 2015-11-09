#include "boost_functions.h" 

//This function is never called. Potentially, it could be a much faster way of implementing the histogram. 
vector<double> boost_histogram(vector<double> data)
{
    a::accumulator_set<double, a::stats<a::tag::mean> > acc; 
    

    //I haven't gotten boost accumulators to work yet, but they are supposedly much faster. 

//    a::accumulator_set<double, stats<a::tag::density > > acc(a::tag::density::cache_size=10, a::tag::density::num_bins=5);

    //typedef boost::iterator_range<std::vector<std::pair<double, double> >::iterator > histogram_type;

    for (int i = 0 ; i < data.size() ; i++) 
    {
      //cout << data[i] ; 
      acc(data[i]) ; 
    }
   
    cout << "From accumulator : " << a::mean(acc) << endl; 
    //histogram_type hist = density(acc) ; 

   return data ; 
}
