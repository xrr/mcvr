#pragma once
#include "V.h"

class Sample :
	public V
{

public:
	Sample(unsigned);
	~Sample(void);
	double Mean(void);
	double MeanSq(void);
	double Variance(void);
	double VarianceCorrected(void);
};