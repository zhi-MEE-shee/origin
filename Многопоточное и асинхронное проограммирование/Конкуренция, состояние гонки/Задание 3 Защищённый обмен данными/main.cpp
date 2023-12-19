#include <algorithm>
#include <iostream>
#include <mutex>


class Data {
	std::mutex mt;
	int a_;

	Data(const Data&) = delete;
	void operator=(const Data&) = delete;

public:
	Data(int a) : a_{ a } {};

	void swap_lg (Data& lhs, Data& rhs) {
		if (&lhs == &rhs) {
			return;
		}
		std::lock(lhs.mt, rhs.mt);
		std::lock_guard lock_lhs(lhs.mt, std::adopt_lock);
		std::lock_guard lock_rhs(rhs.mt, std::adopt_lock);
		std::swap(lhs.a_, rhs.a_);
		std::cout << lhs.a_ << ' ' << rhs.a_ << std::endl;
	}

	void swap_ul(Data& lhs, Data& rhs) {
		if (&lhs == &rhs) {
			return;
		}
		std::unique_lock lock_lhs(lhs.mt);
		std::unique_lock lock_rhs(rhs.mt);
		std::swap(lhs.a_, rhs.a_);
		std::cout << lhs.a_ << ' ' << rhs.a_ << std::endl;
	}

	void swap_sl(Data& lhs, Data& rhs) {
		if (&lhs == &rhs) {
			return;
		}
		std::scoped_lock group_lock(lhs.mt, rhs.mt);
		std::swap(lhs.a_, rhs.a_);
		std::cout << lhs.a_ << ' ' << rhs.a_ << std::endl;
	}

};


int main() {

	Data obj1(1);
	Data obj2(2);

	obj1.swap_lg(obj1, obj2);
	obj1.swap_ul(obj1, obj2);
	obj1.swap_sl(obj1, obj2);
}