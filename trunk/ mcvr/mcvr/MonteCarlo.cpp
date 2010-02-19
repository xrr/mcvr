#include "MonteCarlo.h"
#include "Sample.h"

MonteCarlo::MonteCarlo(Range* pR, BlackScholes* pBS, Payoff* pP)
: _pR(pR), _pBS(pBS), _pP(pP) {}

MonteCarlo::~MonteCarlo(void) {}

double MonteCarlo::Run(unsigned N) {
	//nombre d'étapes sur une simulation de trajectoire:
	int S = _pR->steps;
	double dt = _pR->StepSize();
	Sample sample(N);
	for (unsigned n=0; n<N; n++) {
		Trajectory T(unsigned(S+1));
		T.Set(1,_pBS->S0);
		_pBS->Reset();
		for (int s=1; s<=S; s++)
			T.Set(s,_pBS->NextValue(dt));
		sample.Set(n,(*_pP)(&T));
	}
	return sample.Mean();
}