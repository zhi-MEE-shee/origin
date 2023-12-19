#include <iostream>
#include <thread>
#include <atomic>


std::atomic<int> q = 0;
std::atomic<bool> queue_is_over(true);

void client_count() {
	
	while (queue_is_over) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		q.fetch_add(1);
		std::cout << "Customers queue is equal: " << q.load() << std::endl;
	}
}

void operator_count() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
	while (q != 0) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "Operator is serving " << q.load() << " customer\n";
		q.fetch_sub(1);
	}
	std::cout << "Queue is empty!\n";
}

int main() {

	std::thread th1(client_count);
	std::thread th2(operator_count);
	
	std::this_thread::sleep_for(std::chrono::seconds(10));
	queue_is_over.store(false);

	th1.join();
	th2.join();

	

	return 0;
}


//std::memory_order_relaxed
// 
//std::memory_order_consume
//std::memory_order_acquire атомарная загрузка является операцией захвата
//std::memory_order_release атомарное сохранение - операцией освобождения
// 
//std::memory_order_acq_rel захват и освобождение
// 
//std::memory_order_seq_cst памяти синхронизируется между всеми потоками программы

