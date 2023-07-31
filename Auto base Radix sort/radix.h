#include "vector"
#include "iterator"
#include "climits"
#include "cmath"
#include "cstring"
#include "cstdint"
#include "algorithm"

/// The core sorting algorithm
template<typename iterator>
void _radix(iterator begin, iterator end, int64_t base = -1){
	using type = typename std::iterator_traits<__typeof(iterator)>::value_type;

	const type maxval = std::abs(*max_element(begin, end, [](const type &a, const type &b){
		return (std::abs(a) < std::abs(b));
	}));

	if(maxval == 0) return;

	// It'd be nuts if someone sorts over 2 billion items but better safe than sorry
	const uint64_t size = (end - begin);

	// If not specified, calculate optimal base
	if(base < 0){
		// (N + base) * floor(log(V) / log(base) + 1)
		auto f = [&](double_t x) -> double_t{ 
			return (size + x) * (uint64_t) (log(maxval) / log(x) + 1);
		};

		// Loop until the ith root of V is less than 3
		base = 2;

		for(uint64_t i = 1, lim = log(maxval) / log(3); i <= lim; ++i){
			uint64_t cur = pow(maxval, 1.0 / i);

			if(f(cur) < f(base)) base = cur;
			if(f(cur + 1) < f(base)) base = cur + 1;
			if(f(cur - 1) < f(base)) base = cur - 1;
		}
	}

	const uint64_t loops = (log(maxval) / log(base)) + 1;
	std::vector<std::vector<uint64_t>> bucket(loops, std::vector<uint64_t>(base));
	double_t invpow[loops];

	// For each power of base, we calculate its inverse so that we can do a
	// multiplication instead of division
	double_t div = 1.0;	
	for(uint64_t i = 0; i < loops; ++i){
		invpow[i] = 1.0 / div;
		div *= base;
	}

	// Histograms building
	for(uint64_t i = 0; i < loops; ++i){
		for(iterator it = begin; it < end; ++it){
			type digit = std::abs(*it) * invpow[i];
			type quo = digit * invpow[1];
			digit -= quo * base;

			++bucket[i][digit];
		}

		std::partial_sum(bucket[i].begin(), bucket[i].end(), bucket[i].begin());
	}

	// Reordering
	std::vector<type> helper(size);

	for(uint64_t i = 0; i < loops; ++i){
		if(bucket[i][base - 1] == 0) continue;

		if(i & 1){
			for(iterator it = helper.end() - 1; it >= helper.begin(); --it){
				type digit = std::abs(*it) * invpow[i];
				type quo = digit * invpow[1];
				digit -= quo * base;

				uint64_t pos = bucket[i][digit] - 1;
				*(begin + pos) = *it;

				--bucket[i][digit];
			}
		}
		else{
			for(iterator it = (end - 1); it >= begin; --it){
				type digit = std::abs(*it) * invpow[i];
				type quo = digit * invpow[1];
				digit -= quo * base;

				uint64_t pos = bucket[i][digit] - 1;
				helper[pos] = *it;

				--bucket[i][digit];
			}
		}
	}

	// One last pass
	if(loops & 1){
		for(uint64_t pos = 0; pos < size; ++pos) 
			*(begin + pos) = helper[pos];
	}
}

/// Handles negative elements
template<typename iterator>
void radix(iterator begin, iterator end, int64_t base = -1){
	// Swapping all negative values to the front
	// Then we sort the negative and positive segments separately
	iterator left = begin, right = end - 1, pivot;

	while(true){
		while(left < right && *left < 0) ++left;
		while(right >= left && *right > 0) --right;
		if(left >= right) break;

		std::swap(*left, *right);
		++left;
		--right;
	}

	for(pivot = right; pivot <= left; ++pivot)
		if(pivot >= begin && *pivot > 0) break;

	// Sort
	_radix(begin, pivot, base);
	_radix(pivot, end, base);

    // Reversing the negative segment
    std::reverse(begin, pivot);
}