#include "MonteCarlo.h"
#include <iostream>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

MonteCarlo::MonteCarlo(BlackScholes* pBS, Range* pR, Payoff* pP) : _pBS(pBS), _pR(pR), _pP(pP) {}
MonteCarlo::~MonteCarlo(void) {}

double MonteCarlo::Run(int N) {
	int S = _pR->steps;
	gsl_matrix* pM = gsl_matrix_alloc(N,S);
	for (int n=0; n<N; n++) {
		/*for (int s=0; s<S; s++) {
		double t=_pR->Next();
		gsl_matrix_set(pM,n,s,);
		}*/
		int s=S;
		double T = _pR->ubound;
		gsl_matrix_set(pM,n,s,_pBS->ClosedFormula(T));
	}
	
	double result = 0;
	for (int n=0; n<N; n++) {
		gsl_vector_view rowview = gsl_matrix_row(pM,n); //Extraction de la ligne n
		gsl_vector* Trajectory = &rowview.vector; //Conversion gsl_vector_view -> gsl_vector*
		result+=(*_pP)(Trajectory); // moyenne des payoffs
	}
	return (result/N);
}
