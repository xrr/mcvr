#include "PathIndependantPayoff.h"

double PathIndependantPayoff::operator()(Trajectory* pT) {
	DegeneratedTrajectory DT;
	DT = (DegeneratedTrajectory)(*pT);
	return operator()(&DT);
}

Sample PathIndependantPayoff::operator()(Sample* pS) {
	Sample output(0);
	DegeneratedTrajectory DT;
	for (unsigned i=0; i<pS->Size(); i++) {
		DT.SetLast(pS->Get(i));
		output.Push(operator()(&DT));
	}
	return output;
}
