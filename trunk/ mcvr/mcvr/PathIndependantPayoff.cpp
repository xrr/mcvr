#include "PathIndependantPayoff.h"

double PathIndependantPayoff::operator()(Trajectory* pT) {
	DegeneratedTrajectory DT = (DegeneratedTrajectory)(*pT);
	return operator()(&DT);
}
