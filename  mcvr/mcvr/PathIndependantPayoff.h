#pragma once
#include "Payoff.h"
#include "DegeneratedTrajectory.h"

class PathIndependantPayoff :
	public Payoff
{
public:
	virtual double operator()(DegeneratedTrajectory*)=0;
	double operator()(Trajectory*);
};
