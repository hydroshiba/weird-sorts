#include "radix.h"
#include "timer.h"

#include <cassert>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <random>

int main() {
    int n = 10000000;
    std::vector<int> vec(n);

    std::iota(vec.begin(), vec.end(), 1);
    random_shuffle(vec.begin(), vec.end());
	std::vector<int> arr(vec);

	std::cout << "Start" << std::endl;

    Timer timer;
    timer.start();
    radix(vec.begin(), vec.end());
    auto time = timer.get();

    // for(int i = 0; i < n; ++i) std::cout << vec[i] << ' ';

    std::cout << "Radix time elapsed: " << time << "ms\n";
    assert(std::is_sorted(vec.begin(), vec.end()));

	timer.start();
	std::sort(arr.begin(), arr.end());
	time = timer.get();

	std::cout << "std::sort time elapsed: " << time << "ms\n";
    return 0;
}