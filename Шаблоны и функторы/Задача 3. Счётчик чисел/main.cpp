#include <algorithm>
#include <iostream>
#include <vector>

struct get_sum {

	int sum{ 0 };
	void operator()(int n) { sum += n; }
};


struct get_count {
	int counter{ 0 };
	int operator()(int n) {
		if (n % 3 == 0) {
			++counter;
		}
		return counter;
	}
};


int main() {

	std::vector<int> nums{4, 1, 3, 6, 25, 54};
	std::cout << "[IN]: ";
	for (auto& i : nums) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	
	get_sum sum = std::for_each(nums.begin(), nums.end(), get_sum());
	std::cout << "[OUT]: get_sum() = " << sum.sum << std::endl;
	get_count count = std::for_each(nums.begin(), nums.end(), get_count());
	std::cout << "[OUT]: get_count() = " << count.counter << std::endl;
}