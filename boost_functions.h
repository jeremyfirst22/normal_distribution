#ifndef __BOOST_FUNCTIONS_INCLUDED__
#define __BOOST_FUNCTIONS_INCLUDED__

#include <boost/accumulators/accumulators.hpp> 
#include <boost/accumulators/statistics/stats.hpp> 
#include <boost/accumulators/statistics/mean.hpp> 
#include <boost/accumulators/statistics/density.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <vector> 
#include <iostream>

using namespace std ; 
namespace a=boost::accumulators; 

vector<double> boost_histogram(vector<double>) ; 

#endif
