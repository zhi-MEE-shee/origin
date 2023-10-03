#include <algorithm>
#include <iostream>
#include <vector>


int main() {

	std::vector<double> V {1, 1, 2, 5, 6, 1, 2, 4};
	std::cout << "[IN]: ";
	/* ����� � ������� */
	std::for_each(V.begin(), V.end(), [](int el) {std::cout << el << ' '; });
	std::cout << std::endl;
	/* ���������� */
	std::sort(V.begin(), V.end());

	/* �������� ���������� */
	auto new_end = std::unique(V.begin(), V.end());

	/* �������� ��������� �� ��������� �� ����� �����, �� ��������� �� ����. ����� */
	V.erase(new_end, V.end());

	std::cout << "[OUT]: ";
	/* ����� � ������� */
	std::for_each(V.begin(), V.end(), [](int el) {std::cout << el << ' '; });

	return 0;
}