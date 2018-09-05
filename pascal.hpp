/*------------------------------------------------------------------------------------------------------------
File: pascal.hpp
Class: MAT300
Author: Joel Barba
Date: 02-04-2011

Template meta-programs Pascal's Triangle and generates a look-up table for it.

Template meta-programming utilitizes the compiler's ability to generate classes and 
function definitions at compile-time from templates, as well as it's ability to
optimize compile-time constants; the two allow the programmer to "program" the
compiler to calculate complex equations at compile-time. While the result increases
compile time, it also increases run-time performance by having a generated look-up
table at start up.

------------------------------------------------------------------------------------------------------------*/

#ifndef MATH_PASCAL_HPP
#define MATH_PASCAL_HPP

#include <cstddef>
#include <vector>

namespace math
{
	// defines the condition in which the class diverges to base case definition.
	#define PASCAL_CONDITION(pArg0, pArg1)	\
		(pArg1) == 0 || (pArg0) == (pArg1)

	// the pascal identity value.
	#define PASCAL_IDENTITY(pArg0, pArg1)									\
		pascal_identity<PASCAL_CONDITION(pArg0, pArg1), pArg0, pArg1>::value

	// the pascal identity: (n; k) = (n - 1; k - 1) + (n - 1; k)
	template <bool B, std::size_t N, std::size_t K>
	struct pascal_identity
	{	
		// defines a class-wide constant value for a particular template instance.
		// the definition is recursive, so other template instances are generated until the
		// base case is reached. the constant values are then added at compile time.
		static const std::size_t value = PASCAL_IDENTITY(N - 1, K - 1) + PASCAL_IDENTITY(N - 1, K);
	};

	//explicit class definition - base case: bool = true.
	template <std::size_t N, std::size_t K>
	struct pascal_identity<true, N, K>
	{
		// class-wide constant value is always 1 whenever the first template argument is true.
		static const std::size_t value = 1;
	};

//------------------------------------------------------------------------------------------------------------

	// creates a vector of pascal triangle rows.
	template<std::size_t N, std::size_t K>
	struct pascal_row
	{
		static std::vector<std::size_t> create()
		{
			std::vector<std::size_t> result = pascal_row<N, K - 1>::create();
			result.push_back(PASCAL_IDENTITY(N, K));

			return result;
		}

	};

	// explicit class definition - base case: row N, element 0
	template<std::size_t N>
	struct pascal_row<N, 0>
	{
		static std::vector<std::size_t> create()
		{
			std::vector<std::size_t> result;
			// first vector element is always 1.
			result.push_back(1);

			return result;
		}
	};

//------------------------------------------------------------------------------------------------------------

	// generates pascal triangle recursively; outer vector is rows, vector within is elements.
	template<std::size_t N>
	struct pascal_triangle
	{
		static std::vector<std::vector<std::size_t>> create()
		{
			// create others first, recursively.
			std::vector<std::vector<std::size_t>> result = pascal_triangle<N - 1>::create();

			// push back last row.
			result.push_back(pascal_row<N, N>::create());

			// return result.
			return result;
		}
	};

	// explicit class definition - base case: row 0, push one row with one element
	template<>
	struct pascal_triangle<0>
	{
		static std::vector<std::vector<std::size_t>> create()
		{
			std::vector<std::vector<std::size_t>> result;
			
			// push back combination: (0; 0)
			result.push_back(pascal_row<0, 0>::create());

			return result;
		}
	};

	// cleans up definitions to avoid #define bleed over into other files.
	#undef PASCAL_CONDITION
	#undef PASCAL_IDENTITY
}

#endif
