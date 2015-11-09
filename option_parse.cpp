#include "option_parse.h"

using namespace std ; 

namespace
{
    const size_t SUCCESS = 0 ; 
    const size_t ERROR_IN_COMMAND_LINE = 1 ; 
    const size_t ERROR_FILE_READ = 2 ; 
    const size_t ERROR_UNHANDLED_EXCEPTION = 3 ; 
}

void description(){
    printf("\n\
This program returns the normal distribution of data from a file. It will calculate:\n\
\t1) A histogram of occurances, using a user-specified number of bins. \n\
\t2) The mean and standard deviation of all data. \n\
\t3) The most probable value (highest occupied bin of histogram)\n" ) ;
    example(); 
    return ; 
}

void example(){
    printf("\nExample: ./tiltAngle --file nitrileangle.dat --out distribution.txt -n 10000\n\n"); 
    return ; 
}

int read_options(int argc, char**  argv, options& opt)
{
    ifstream fileHandle ; 
    try
    {
        namespace po = boost::program_options ;
        //Add program options. 
        po::options_description desc("Options") ;
        desc.add_options()
          ("help,h", "Print help message")
          ("file,f", po::value<string>(&opt.inFile)->required(),"Specify input file") 
          ("out,o", po::value<string>(&opt.outFile)->required(),"Specify output file") 
          ("number,n", po::value<int>(&opt.numBins)->default_value(100),"Specify number of bins") 
          ("gaussian-fit,g", po::value<string>(&opt.gaussOut), "Print a gaussian fit to a suplied file name")
          ("overwrite", po::bool_switch(&opt.overwrite),"Force overwrite of existing output file."); 
          po::variables_map vm ;
        try
        {
            //Read command line options. 
             po::store(po::parse_command_line(argc, argv, desc), vm);
            if (vm.count("help"))
            {
                description();
                cout << desc << endl ;
                exit(1); 
                //return SUCCESS ;
                //Catch help flag and exit 
            }
            po::notify(vm) ;
        }
    
        catch(po::error& e)
        {
            description();
            cerr << desc << endl ;
            cerr << "ERROR: " << e.what() << endl << endl;
            exit(1); 
            //return ERROR_IN_COMMAND_LINE ;
            //Catch incorrect options
        }
        checkFile(opt.outFile, opt.overwrite) ; 
        if (vm.count("gaussian-fit"))
        {
            checkFile(opt.outFile,opt.overwrite) ; 
            opt.gaussBool = true ; 
        }
    }
    catch(exception& e)
    {
        cerr << "ERROR: Unhandled exception reached the top of main: " << e.what() << " , application will exit " << endl ;
        exit(1) ; 
        //return ERROR_UNHANDLED_EXCEPTION ;
    }
    return SUCCESS; 
}



