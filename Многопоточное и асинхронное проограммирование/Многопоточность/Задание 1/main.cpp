#include <iostream>
#include <thread>

using namespace std::chrono_literals;

thread_local int q = 0;


void client_count() {

	while (q != 20) {
		std::this_thread::sleep_for(60ms);
		++q;
		std::cout << "client queue: " << q << std::endl;
	}
}

void operator_count() {
	q = 21;
	while (q != 1) {
		std::this_thread::sleep_for(120ms);
		q--;
		std::cout << "operator: " << q << std::endl;
	}
}

int main() {

	std::thread th1(client_count);
	std::thread th2(operator_count);

	th1.join();
	th2.join();

	return 0;
}