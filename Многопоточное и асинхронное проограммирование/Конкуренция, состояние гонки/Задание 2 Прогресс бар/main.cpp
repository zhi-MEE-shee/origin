#include <iostream>
#include <iomanip>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>

#pragma execution_character_set("utf-8")

std::mutex mut;

void printProgressBar(int percent) {
    const int width = 15;
    int filledLength = (percent * width) / 100;

    std::string bar;

    for (int i = 0; i < filledLength; i++) {
        bar += "█";
    }
    for (int i = filledLength; i < width; i++) {
        bar += " ";
    }
    std::cout << "\r" << bar;
    std::cout.flush();
}

void print(int id) {
    std::unique_lock ul(mut);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    std::cout << id << "   " << std::this_thread::get_id() << "\t\t";

    auto start = std::chrono::system_clock::now();

   /* for (int i = 0; i <= 100; i++) {
        printProgressBar(i);
    }*/

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> diff = end - start;

    std::cout << "\t" << diff.count() << " ms";
    std::cout << std::endl;
}



int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "#   id\t\tProgress bar\t\Time\n";

    std::vector<std::thread> th;
    for (int j = 0; j < 6; ++j) {
        th.push_back(std::thread(print, j));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    for (auto& it : th) {
        it.join();
    }

    return 0;
}




