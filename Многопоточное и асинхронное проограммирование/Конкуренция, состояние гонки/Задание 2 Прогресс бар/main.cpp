#include <iostream>
//#include <iomanip>
//#include <chrono>
#include <mutex>
#include <string>
#include <thread>
#include "Timer.h"
#include <vector>
#include <Windows.h>


#pragma execution_character_set("utf-8")

std::mutex mut;

//void printProgressBar(int percent) {
//
//   
//    const int width = 15;
//    int filledLength = (percent * width) / 100;
//
//    std::string bar;
//
//    for (int i = 0; i < filledLength; i++) {
//        bar += "█";
//    }
//    for (int i = filledLength; i < width; i++) {
//        bar += " ";
//    }
//    std::cout << "\r" << bar;
//    std::cout.flush();
//}

//
//void print(int id) {
//    std::unique_lock ul(mut);
//
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    
//    std::cout << id << "   " << std::this_thread::get_id() << "\t\t";
//
//    auto start = std::chrono::system_clock::now();
//
//   /* for (int i = 0; i <= 100; i++) {
//        printProgressBar(i);
//    }*/
//
//    auto end = std::chrono::system_clock::now();
//
//    std::chrono::duration<double> diff = end - start;
//
//    std::cout << "\t" << diff.count() << " ms";
//    std::cout << std::endl;
//}

//int main() {
//    SetConsoleCP(CP_UTF8);
//    SetConsoleOutputCP(CP_UTF8);
//
//    //std::cout << "#   id\t\tProgress bar\t\Time\n";
//
//    //std::vector<std::thread> th;
//    //for (int j = 0; j < 6; ++j) {
//    //    th.push_back(std::thread(print, j));
//    //    std::this_thread::sleep_for(std::chrono::milliseconds(10));
//    //}
//
//    //for (auto& it : th) {
//    //    it.join();
//    //}
//
//    ////std::string block = "▂▄▆█"
//    return 0;
//}


void ProgressBar(int total, int current)
{
 
    float progress = static_cast<float>(current) / total;
    int barWidth = 12;
    consol_parameter cp;
    cp.SetPosition(15, current);

    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i)
    {
        if (i < pos)
            std::cout << "█";
        else if (i == pos)
            std::cout << "▄";
        else
            std::cout << " ";
    }

 //   std::cout << " \r";
    std::cout.flush();
}

void print(int id)
{
    for (int i = 0; i < id; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        Timer timer;
        std::lock_guard lock(mut);
        consol_parameter cp1;
        cp1.SetPosition(0, id);
        std::cout << id << "   " << std::this_thread::get_id() << "\t\t";
        ProgressBar(id, i + 1);
        consol_parameter end;
        end.SetPosition(24, id);
        timer.print();
    }
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "#   id\t\tProgress bar\t\Time\n";

    const int numThreads = 5;
    const int numIterations = 5;

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i){
        threads.emplace_back(print, i + 1);
    }

    for (auto& thread : threads){
        thread.join();
    }

    return 0;
}