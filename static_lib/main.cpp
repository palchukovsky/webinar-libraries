#include "sum.h"

#include <iostream>

int main() {

	const auto &result = library::sum(1, 2);

	std::cout << "Hello! The result is " << result << "!" << std::endl;

	return 0;
}