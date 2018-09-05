/*------------------------------------------------------------------------------------------------------------
File: binomial_coefficient.cpp
Class: MAT300
Author: Joel Barba
Date: 02-04-2011

Implements the binomial)coefficient class.
------------------------------------------------------------------------------------------------------------*/
#include "binomial_coefficient.hpp"
#include "pascal.hpp"

namespace math
{
	binomial_coefficient::binomial_coefficient() :
	mPascalTriangle(pascal_triangle<limit>::create())
	{}

	std::size_t binomial_coefficient::choose(std::size_t n, std::size_t k) const
	{
		const std::vector<std::size_t>& row = mPascalTriangle[n];
		return row[k];
	}
}