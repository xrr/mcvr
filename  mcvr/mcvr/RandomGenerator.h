#pragma once

class RandomGenerator {
public:
	RandomGenerator(void);
	~RandomGenerator(void);
	virtual double Next()=0;
};
