#pragma once
#include "Payoff.h"
#include "DegeneratedTrajectory.h"
#include "Sample.h"

class PathIndependantPayoff :
	public Payoff
{
public:
	virtual double operator()(DegeneratedTrajectory*)=0;
	double operator()(Trajectory*);
	Sample operator()(Sample*);
};
