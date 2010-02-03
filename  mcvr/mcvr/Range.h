#pragma once
#include <iostream>

class Range
{
public:
	Range(double=0, double=1);
	~Range(void);
	
	double lbound;
	double ubound;

	double* GetBounds(void);
	double GetLength(void);
	friend std::ostream& operator<< (std::ostream&, Range&);

};

