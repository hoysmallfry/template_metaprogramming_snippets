/*------------------------------------------------------------------------------------------------------------
File: binomial_coefficient.cpp
Author: Joel Barba
Date: 03-07-2012

Exemplifies use of the pascal triangle for use with binomial coefficient.
------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include "binomial_coefficient.hpp"

int main()
{
	math::binomial_coefficient bc;

	for(auto n = 0; n < math::binomial_coefficient::limit; ++n)
	{
		for(auto k = 0; k < n + 1; ++k)
			std::cout << bc.choose(n, k) << " ";

		std::cout << "\n";
	}

	system("pause");

	return 0;
}
