#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> // std::setprecision
#include <vector>
#include <list>
#include <deque>
#include <set>

//полезные typedef
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::pair<int, int> ii;

//полезные define
#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define maxT(t) std::numeric_limits<t>::max()
#define minT(t) std::numeric_limits<t>::min()
#define lowestT(t) std::numeric_limits<t>::lowest()
#define all(v) (v).begin(), (v).end()

int main(){
    // ускорение кода
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    
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
    // int16_t==int; int32_t==long int; int64_t==long long int

    double const PI = 3.14159;
    std::cout << std::fixed << std::setprecision(4) << PI << std::endl; // fixed - отсчет чисел без целой части, setprecision(x) - округлить до x знаков после запятой

    std::cout << 0b111111 << std::endl; // двоичная сс
    std::cout << 01234567 << std::endl; // 8-ричная сс
    std::cout << 0x111111 << "\n\n"; // 16-ричная сс

    //строки
    std::string s = "prevName: Artem";
    s.replace(s.find("prevName"), std::string("prevName").size(), "newName"); // замена символом строки

    std::string age = "16";
    std::cout << stoi(age) << std::endl; //строка в число 

    // лямбда функции
    // лямбда функцию необязательно называть. в квадратных скобках указываются ссылки на используемые переменные из внешнего контекста
    int counter = 5;
    auto incCounter = [&counter](int num) {
        return counter += num;
    };
    std::cout << incCounter(10) << "\n\n";

    //выделение памяти
    int *a = new int(5); //выделение памяти под переменную содержащую 5
    delete a; //освобождение памяти

    int *b = new int[100]; //выделение для массива из 100 значений
    delete [] b;//освобождение для массива

    // vector - динамический массив
    // begin(arr) == arr.begin(); 
    // end(arr) == arr.end(); 
    // arr.back() - последний эл.
    // arr.front() - первый эл 
    // next(arr) == arr.next(); 
    // prev(arr) == arr.prev()
    std::vector<int> v1 {1,2,3};// {1, 2, 3}
    std::vector<int> v2 (3,5);  // {5, 5, 5} (3 раза по 5s)

    int *firstElP = &v1[0]; //удобная работа с элементами массива через указатели
    int *secondElP = firstElP+1;
    std::cout << *firstElP << " " << *secondElP << std::endl;

    v1.push_back(1);            // добавление нового элемента в конец вектора
    v1.reserve(10);             // зарезервировать память для 10 значений в векторе (ускоряет другие методы, например push_back)
    v1.resize(10, 1);           // изменение кол-ва элементов вектора (1арг - новое кол-во элементов, 2арг - элементы, которыми нужно заполнить (по дефолту 0))
    v1.insert(v1.begin(), 123); // вставка в вектор перед 0 элементом числа 123
    v1.insert(v1.begin() + 5, v2.begin(), v2.end()); // вставка в вектор другого вектора перед 5 элементом

    //list - связанный список. методы такие же как у вектора, но есть и новые:
    std::list<int> l1 {1,2,3};
    l1.push_back(8);            // добавление нового элемента в конец списка
    l1.push_front(5);           // добавление нового элемента в начало списка

    std::list<int> l2(10);
    l2.insert(++ ++ ++ ++ ++l2.begin(), l1.begin(), l1.end()); // вставка в список другого списка перед 5 элементом

    // deque - очередь (много памяти занимает). методы такие же как у вектора, но есть еще и push_front()
    std::deque d1 {1, 2, 3, 4};
    d1.push_back(2); // добавление нового элемента в конец списка
    d1.push_front(5); // добавление нового элемента в начало списка

    // set - множество (упорядоченный набор уникальных элементов); красно-черное дерево. push_back заменяется на insert
    std::set<int> s1 {1,2,2};   // {1, 2}
    s1.insert(5);               // добавление нового элемента в конец сета
    s1.find(1);                 //  поиск определенного элемента в сете
    s1.count(1);                // кол-во определенных элементов в сете
}