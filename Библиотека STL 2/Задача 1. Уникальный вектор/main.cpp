#include <algorithm>
#include <iostream>
#include <vector>


int main() {

	std::vector<double> V {1, 1, 2, 5, 6, 1, 2, 4};
	std::cout << "[IN]: ";
	/* вывод в консоль */
	std::for_each(V.begin(), V.end(), [](int el) {std::cout << el << ' '; });
	std::cout << std::endl;
	/* сортировка */
	std::sort(V.begin(), V.end());

	/* удаление дубликатов */
	auto new_end = std::unique(V.begin(), V.end());

	/* удаление диапазона от указателя на новый конец, до указателя на пред. конец */
	V.erase(new_end, V.end());

	std::cout << "[OUT]: ";
	/* вывод в консоль */
	std::for_each(V.begin(), V.end(), [](int el) {std::cout << el << ' '; });

	return 0;
}