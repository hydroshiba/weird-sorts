#ifndef CALIBRATED_RADIX_HPP
#define CALIBRATED_RADIX_HPP

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iterator>
#include <numeric>

// Arbitrary base logarithm of an integer, return floored value

template<typename Type>
unsigned int log(Type N, Type base) {
	return (N ? 1 + log(N / base, base) : 0);
}

template<typename iterator>
void radix(iterator begin, iterator end){
	using Type = typename std::iterator_traits<__typeof(iterator)>::value_type;
	size_t size = (end - begin);

	Type max = *std::max_element(begin, end);
	if(max < 1) return;

	// The complexity function (N + base) * floor(log(V) / log(base) + 1)

	auto f = [&](Type x) { 
		return (size + x) * Type(log(max, x) + 1);
	};

	// Calculate optimal base, loop until the ith root of V is less than 3
	// The base should be smaller than max value, using the same integer Type for the base is sufficient
	
	Type base = 2, lim = log(max, Type(3));

	for(Type i = 1; i <= lim; ++i) {
		Type current = f(base), new_base = pow(max, 1.0 / i);
		if(new_base < 2) break;

		// Since the base value is integer, we need to check the min value of {new_base - 1, new_base, new_base + 1}

		if(f(new_base) < current) base = new_base;
		if(f(new_base + 1) < current) base = new_base + 1;
		if(new_base > 2 && f(new_base - 1) < current) base = new_base - 1;
	}

	// Sorting process

	size_t *bucket = new size_t[base]();
	Type *temp = new Type[size]();

	Type loops = log(max, base) + 1;
	Type power = 1;

	for(Type i = 0; i < loops; ++i) {

		// Histograms building

		memset(bucket, 0, sizeof(size_t) * base);

		for(iterator it = begin; it != end; ++it) {
			Type digit = (*it / power) % base;
			++bucket[digit];
		}

		std::partial_sum(bucket, bucket + base, bucket);

		// Reordering

		for(iterator it = (end - 1); it >= begin; --it) {
			Type digit = (*it / power) % base;
			--bucket[digit];
			temp[bucket[digit]] = *it;
		}

		for(iterator it = begin; it != end; ++it)
			*it = temp[it - begin];

		power *= base;
	}

	delete[] bucket;
	delete[] temp;
}

#endif