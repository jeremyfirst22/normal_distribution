#include "fit_polynomial.h"

using namespace std ; 

void fit_polynomial(vector<vector<double> > data, double avg , int numTerms , string outFile) {
    cout << "fit_polynomial called with " << numTerms << " number of terms" << endl; 
    
    cout << "Data is of size : " << data.size() << endl; 
    double sumSquares ; 
    gsl_vector * Y = gsl_vector_calloc(data.size()); 
    gsl_vector * a = gsl_vector_calloc(numTerms) ; 
    gsl_matrix * X = gsl_matrix_calloc(data.size(),numTerms) ; 
    gsl_matrix * cov = gsl_matrix_calloc(numTerms, numTerms) ; 

    for (int i = 0 ; i < data.size() ; i++)
    {
        gsl_vector_set(Y, i, data[i][1]) ; 
    }
    
    /*for (int i = 0 ; i < 5 ; i++)
    {
        cout << gsl_vector_get(Y, i) << endl ;
    }*/

    for (int i = 0 ; i < data.size() ; i++) {
        for (int j = 0 ; j < numTerms ; j++){
            //                      
            // f(x) = a_i*(x - avg)^i
            //
            gsl_matrix_set(X,i,j,pow(data[i][0]-avg,j)) ; 
        }
    }   
    
    /*for (int i = 0 ; i < data.size() ; i++){
        for (int j = 0 ; j < numTerms ; j++){
            printf("%f  ",gsl_matrix_get(X,i,j)) ; 
        }
        printf("\n")  ; 
    }*/


    {
        gsl_multifit_linear_workspace * w = gsl_multifit_linear_alloc(data.size(), numTerms) ; 
        gsl_multifit_linear(X, Y, a, cov, &sumSquares, w) ; 
        gsl_multifit_linear_free(w) ; 
    }


    /*printf(" y = %f ",gsl_vector_get(a,0)) ; 
    for (int i = 1 ; i < numTerms ; i++) {
        printf(" + %f*(x - %f)**%i",gsl_vector_get(a,i),avg,i) ; 
    }
    printf("\n") ;*/ 
    vector< vector<double> > polyFit ; 
    double y ; 
    double x ; 
    for (int i = 0 ; i < data.size() ; i++) {
        vector< double> row ; 
        x = data[i][0] ; 
        y = gsl_vector_get(a,0) ; 
        for (int j = 1 ; j < numTerms ; j++){
            y += gsl_vector_get(a,j) * pow(x - avg,j) ; 
        }
        row.push_back(x) ; 
        row.push_back(y) ; 
        polyFit.push_back(row) ; 
    }
    print(polyFit, outFile) ; 

    gsl_vector_free(a) ; 
    gsl_vector_free(Y) ; 
    gsl_matrix_free(X) ; 
    gsl_matrix_free(cov) ; 

    return ; 
}
