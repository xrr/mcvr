#include "Tests.h"

#include "Pipe.h"
#include "Call.h"

int main() {

	Tests::BaseTests();
	//Tests::RNGTests();
	Tests::BSTests();
	Tests::PayoffTests();
	Tests::MCTests();

	return 0;
}
