/*------------------------------------------------------------------------------------------------------------
File: binomial_coefficient.hpp
Class: MAT300
Author: Joel Barba
Date: 02-04-2011

The class declared in this file represents the bimonial coeficient, up to 47 rows
------------------------------------------------------------------------------------------------------------*/
#ifndef MATH_BINOMIAL_COEFFICIENT
#define MATH_BINOMIAL_COEFFICIENT

#include <cstddef>
#include <vector>

namespace math
{
	class binomial_coefficient
	{
	public:
		// kind of a magic number. 34 avoids integral constant overflow.
		static const int limit = 34;

		binomial_coefficient();
		std::size_t choose(std::size_t n, std::size_t k) const;

	private:
		std::vector<std::vector<std::size_t>> mPascalTriangle;

	};
}

#endif
