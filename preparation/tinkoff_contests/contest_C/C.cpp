#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>

namespace mp = boost::multiprecision;

int main() {
    auto start_time = std::chrono::steady_clock::now();

    int n = 1000; // или другое значение

    mp::cpp_int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    auto end_time = std::chrono::steady_clock::now();
    double execution_time = std::chrono::duration<double>(end_time - start_time).count();

    std::cout << "Факториал числа " << n << " равен " << result << std::endl;
    std::cout << "Время выполнения: " << execution_time << " секунд" << std::endl;

    return 0;
}
