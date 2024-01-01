#include <iostream>
#include <vector>
#include <iomanip> // std::setprecision

//полезные using
using ll = long long int;
using pii = std::pair<int, int>;
using pll = std::pair<long, long>;

//полезные define
#define max(t) std::numeric_limits<t>::max()
#define min(t) std::numeric_limits<t>::min()
#define lowest(t) std::numeric_limits<t>::lowest()

int main(){
    // пары элементов
    std::pair<int, double> pair{1, 3.14};
    std::cout << "Pair: (" << pair.first << ", " << pair.second << ")\n\n";

    // указатели
    std::string name = "Artem";
    std::cout << &name << std::endl; //адрес в памяти на переменную

    std::string *pName = &name; //сохранение адреса в памяти на переменную в другую переменную (& - ссылка, * - указатель на ссылку)
    std::cout << pName << std::endl; // адрес на переменную
    std::cout << *pName << "\n\n"; // значение переменной

    // числа
    std::cout << -5E15L << std::endl;  // -5^10*15 (L - для того, чтобы вывелось число типа long)
    std::cout << (int)1E9+7 << std::endl; // (10^9) + 7
    std::cout << static_cast<long long>(9e16L) << " == " << (long long)(9e16L) << std::endl;

    double const PI = 3.14159;
    std::cout << std::fixed << std::setprecision(4) << PI << std::endl; // fixed - отсчет чисел без целой части, setprecision(x) - округлить до x знаков после запятой

    std::cout << 0b111111 << std::endl; // двоичная сс
    std::cout << 01234567 << std::endl; // 8-ричная сс
    std::cout << 0x111111 << "\n\n"; // 16-ричная сс

    // лямбда функции
    // лямбда функцию необязательно называть. в квадратных скобках указываются ссылки на используемые переменные из внешнего контекста
    int counter = 5;
    auto incCounter = [&counter](int num) {
        return counter += num;
    };
    std::cout << incCounter(5);
}