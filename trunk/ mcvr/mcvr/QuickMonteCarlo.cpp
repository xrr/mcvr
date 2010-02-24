#include "QuickMonteCarlo.h"
#include "Sample.h"

QuickMonteCarlo::QuickMonteCarlo(Range* pR, Lognormal* pL, PathIndependantPayoff* pPIP) :
MonteCarlo(pR, pL, pPIP),
_pL(pL), _pPIP(pPIP) {}

QuickMonteCarlo::~QuickMonteCarlo(void) {}

double QuickMonteCarlo::Run(unsigned N) {
	double T = _pR->Length();
	Sample sample(N);
	for (unsigned n=0; n<N; n++) {
		DegeneratedTrajectory DT;
		DT.SetLast(_pL->Value(T));
		sample.Set(n,(*_pPIP)(&DT));

	}
	std::cout << "Mean: " << sample.Mean() << std::endl;
	std::cout << "Variance: " << sample.Variance() << std::endl;
	return sample.Mean();
}