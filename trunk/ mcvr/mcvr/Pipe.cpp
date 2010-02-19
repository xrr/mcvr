#include "Pipe.h"

Pipe::Pipe(const char* filename)
:_newstream(std::ofstream(filename, std::ios::trunc)) {
	_oldbuffer = std::cout.rdbuf(_newstream.rdbuf());
}

Pipe::~Pipe(void) {
	std::cout.rdbuf(_oldbuffer);
}