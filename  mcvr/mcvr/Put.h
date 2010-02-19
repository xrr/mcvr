#pragma once
#include "PathIndependantPayoff.h"
#include "DegeneratedTrajectory.h"

class Put :
	public PathIndependantPayoff
{
public:
	double K; //Strike
	Put(double=90);
	~Put(void);
	double operator()(DegeneratedTrajectory*);

};
