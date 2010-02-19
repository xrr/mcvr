#pragma once
#include <iostream>
#include <fstream>

class Pipe {
	std::ofstream _newstream;
	std::streambuf* _oldbuffer;
public:
	Pipe(const char* = "Pipe.txt");
	~Pipe(void);
};





