#pragma once

class RandomGenerator {
public:
	RandomGenerator(void);
	~RandomGenerator(void);

	virtual double Nextdouble()=0;
	//virtual int Next()=0;
};
