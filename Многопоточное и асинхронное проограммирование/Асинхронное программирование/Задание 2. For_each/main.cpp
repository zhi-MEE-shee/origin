#include <iostream>
#include <future>
#include <vector>


template<typename It, typename Func>
void for_each_iteration(It begin, It end, Func f) { 

	auto length = std::distance(begin, end);
	if (length == 0) {
		return;
	}
	
	if (length < 25) {
		std::for_each(begin, end, f);
		return;
	}
	else {
		It const middle = begin + length / 2;
		std::future<void> first_half = std::async(&for_each_iteration<It, Func>, begin, middle, f);
		for_each_iteration(middle, end, f);
		first_half.get(); //ожидание завершения итерации по первой половине
	}
}


int main() {
	std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };

	for_each_iteration(data.begin(), data.end(), [](int x) {
		std::cout << x << " "; 
	});

}
