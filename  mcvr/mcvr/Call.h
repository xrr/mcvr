#pragma once
#include "PathIndependantPayoff.h"
#include "DegeneratedTrajectory.h"

class Call :
	public PathIndependantPayoff
{
public:
	double K; //Strike
	Call(double=110);
	~Call(void);
	double operator()(DegeneratedTrajectory*);

};
