#include "Chrono.h"
#include <iostream>
#include <iomanip>

Chrono::Chrono(bool autodisp, bool text)
: _start(clock()), _autodisp(autodisp), _text(text) {}

double Chrono::Elapsed(void) {
	return ((double)clock() - _start) / CLOCKS_PER_SEC;
}

Chrono::~Chrono(void){
	if (_autodisp)
		std::cout << std::setprecision(6) << this->Elapsed()
		<< (_text?" seconds":"") << std::endl;
}
