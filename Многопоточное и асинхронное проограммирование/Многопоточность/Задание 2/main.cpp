#include <algorithm>
#include <chrono> 
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std::chrono_literals;


void vec_summ(const std::vector<int>&V1, const std::vector<int>&V2, std::vector<int>& res ) {
	
	std::for_each(res.begin(), res.end(), [&V1, &V2](int& el) { el = (V1[el] * V2[el]); });
}


int main() {

	setlocale(LC_ALL, "Russian");

	std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency() << std::endl;	

	for (int i = 1000; i < 1000001; i *= 10){ std::cout << "\t\t" << i ; }
	std::cout << std::endl;


	for (int k = 1; k < 17; k *= 2) {

		std::cout << k << ((k != 1) ? " threads " : " thread ");

		for (int i = 1000; i < 1000001; i *= 10) {

			std::vector<int> V1(i, 6);
			std::vector<int> V2(i, 2);
			std::vector<int> res(i);
			
			auto start = std::chrono::system_clock::now();

			std::vector<std::thread> th;
			for (int i = 0; i < k; ++i) {
				th.push_back(std::thread(vec_summ, std::ref(V1), std::ref(V2), std::ref(res)));
			}

			for (auto& it : th) {
				it.join();
			}

			auto end = std::chrono::system_clock::now();

			std::chrono::duration<double> diff = end - start;
			std::cout << "\t" << diff.count() << " ms";
		}
		std::cout << std::endl;

	}

	return 0;
}