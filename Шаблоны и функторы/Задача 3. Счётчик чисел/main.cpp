#include <algorithm>
#include <iostream>
#include <vector>


template <typename T>
class get_count
{
	T counter{ 0 };
public:
	T operator()(int n) {
		if (n % 3 == 0) {
			++counter;
		}
		return counter;
	}
	T get_val() { return counter;  }
};

template <typename T>
class get_sum
{
	T sum{ 0 };
public:
	void operator()(int n) { sum += n; }
	T get_val() { return sum; }
};

//
//struct get_sum {
//
//	int sum{ 0 };
//	void operator()(int n) { sum += n; }
//};
//
//
//struct get_count {
//	int counter{ 0 };
//	int operator()(int n) {
//		if (n % 3 == 0) {
//			++counter;
//		}
//		return counter;
//	}
//};

int main() {

	std::vector<int> nums{4, 1, 3, 6, 25, 54};
	std::cout << "[IN]: ";
	for (auto& i : nums) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	
	get_sum<int> sum = std::for_each(nums.begin(), nums.end(), get_sum<int>());
	std::cout << "[OUT]: get_sum() = " << sum.get_val() << std::endl;
	get_count<int> count = std::for_each(nums.begin(), nums.end(), get_count<int>());
	std::cout << "[OUT]: get_count() = " << count.get_val() << std::endl;
}