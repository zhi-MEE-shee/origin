#include <algorithm>
#include <future>
#include <iostream>
#include <vector>

// Функция для поиска минимального элемента
void find_min(std::vector<int>& arr, int start, int end, std::promise<int> prom) {
    int min = start;
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    prom.set_value(min);  
}

// Функция для сортировки массива методом выбора
void selection_sort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        
        std::promise<int> min_index;
        std::future<int> fut_index = min_index.get_future();
        auto ft = std::async(find_min, ref(arr), i, n - 1, std::move(min_index));
        
        int min = fut_index.get();
        std::swap(arr[i], arr[min]);
    }
}

int main() {
    std::vector<int> arr = { 7, 5, 4, 2, 6, 1, 9, 8, 3 };
 
    selection_sort(arr);

    for (const auto& i : arr) {
        std::cout << i << " ";
    }

    return 0;
}