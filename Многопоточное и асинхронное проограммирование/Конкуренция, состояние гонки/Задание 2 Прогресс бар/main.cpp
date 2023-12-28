#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include "Timer.h"
#include <vector>
#include <Windows.h>


#pragma execution_character_set("utf-8")

std::mutex mut;

void print(int id, const int length) {
   
    consol_parameter cp;
    std::unique_lock ul(mut);
    cp.SetPosition(0, id);
    std::cout << id << "   " << std::this_thread::get_id() << "\t\t\t";
    ul.unlock();
    int k = 0;
    Timer timer;
    while (k < length) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ul.lock();
        cp.SetPosition(k + 13, id);
        std::cout << "█";
        ul.unlock();
            ++k;
    }
    ul.lock();
    cp.SetPosition(k + 15, id);
    timer.print();
    ul.unlock();  
}



int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "#   id\t\tProgress bar\t\Time\n";

    const int num_threads = 5;
    const int bar_length = 15;

    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i){
        threads.emplace_back(print, i + 1, bar_length);
    }

    for (auto& thread : threads){
        thread.join();
    }
    consol_parameter cpo;
    cpo.SetPosition(0, num_threads + 1);

    return 0;
}