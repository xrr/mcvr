#pragma once
#include <time.h>

class Chrono
{
	bool _autodisp;
	bool _text;
	clock_t _start;
public:
	Chrono(bool=1,bool=0);
	~Chrono(void);
	double Elapsed(void);
};
