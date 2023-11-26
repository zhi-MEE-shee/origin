#include <algorithm>
#include <chrono> 
#include <iostream>
#include <thread>
#include <vector>

size_t size = 1000;


void vec_summ(const std::vector<int>&V1, const std::vector<int>&V2, std::vector<int>& res ) {
	
	std::for_each(res.begin(), res.end(), [&V1, &V2](int& el) { el = (V1[el] * V2[el]); });
}



int main() {

	setlocale(LC_ALL, "Russian");

	std::cout << "Количество аппаратных ядер: " << std::thread::hardware_concurrency() << std::endl;

	std::vector<int> V1(size, 3);
	std::vector<int> V2(size, 2);
	std::vector<int> res(size);

	auto start = std::chrono::steady_clock::now();
	
	std::thread th (vec_summ, std::ref(V1), std::ref(V2), std::ref(res));
	
	auto end = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << diff.count() << " ms" << std::endl;

	// для записи результата
	//std::vector<std::chrono::milliseconds> func_time;
	//func_time.push_back(diff);
	
	th.join();

	return 0;
}