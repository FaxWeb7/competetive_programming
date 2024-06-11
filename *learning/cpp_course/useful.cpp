#include <bits/stdc++.h>
#include <iostream>
#include <iomanip> // setprecision
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

//полезные typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;

//полезные define
#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define maxT(t) numeric_limits<t>::max()
#define minT(t) numeric_limits<t>::min()
#define lowestT(t) numeric_limits<t>::lowest()
#define all(v) (v).begin(), (v).end()

#define F first
#define S second
#define PB push_back
#define MP make_pair

int main(){
    // ускорение кода
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    // указатели
    string name = "Artem";
    cout << &name << endl; //адрес в памяти на переменную

    string *pName = &name; //сохранение адреса в памяти на переменную в другую переменную (& - ссылка, * - указатель на ссылку)
    cout << pName << endl; // адрес на переменную
    cout << *pName << "\n\n"; // значение переменной

    // поиск в векторе бинарный и получение индекса
    vector<int> v;
    int minNIndex1 = upper_bound(all(v), 5) - v.begin(); //индекс числа большего пяти
    int minNIndex2 = lower_bound(all(v), 5) - v.begin(); //индекс числа большего или равному пяти

    // числа
    cout << -5E15L << endl;  // -5^10*15 (L - для того, чтобы вывелось число типа long)
    cout << (int)1E9+7 << endl; // (10^9) + 7
    cout << static_cast<long long>(9e16L) << " == " << (long long)(9e16L) << endl;
    // int16_t==int; int32_t==long int; int64_t==long long int

    double const PI = 3.14159;
    cout << fixed << setprecision(4) << PI << endl; // fixed - отсчет чисел без целой части, setprecision(x) - округлить до x знаков после запятой
    cout << setfill('0') << setw(2) << 5; //добавление ведущих нулей если длина последующего числа меньше 2

    cout << 0b111111 << endl; // двоичная сс
    cout << 01234567 << endl; // 8-ричная сс
    cout << 0x111111 << "\n\n"; // 16-ричная сс

    //строки
    string s = "prevName: Artem";
    s.replace(s.find("prevName"), string("prevName").size(), "newName"); // замена символом строки

    string age = "16";
    cout << stoi(age) << endl; //строка в число 

    // лямбда функции
    // лямбда функцию необязательно называть. в квадратных скобках указываются ссылки на используемые переменные из внешнего контекста
    int counter = 5;
    auto incCounter = [&counter](int num) {
        return counter += num;
    };
    cout << incCounter(10) << "\n\n";

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
    vector<int> v1 {1,2,3};// {1, 2, 3}
    vector<int> v2 (3,5);  // {5, 5, 5} (3 раза по 5s)

    int *firstElP = &v1[0]; //удобная работа с элементами массива через указатели
    int *secondElP = firstElP+1;
    cout << *firstElP << " " << *secondElP << endl;

    v1.push_back(1);            // добавление нового элемента в конец вектора
    v1.reserve(10);             // зарезервировать память для 10 значений в векторе (ускоряет другие методы, например push_back)
    v1.resize(10, 1);           // изменение кол-ва элементов вектора (1арг - новое кол-во элементов, 2арг - элементы, которыми нужно заполнить (по дефолту 0))
    v1.insert(v1.begin(), 123); // вставка в вектор перед 0 элементом числа 123
    v1.insert(v1.begin() + 5, v2.begin(), v2.end()); // вставка в вектор другого вектора перед 5 элементом

    //list - связанный список. методы такие же как у вектора, но есть и новые:
    list<int> l1 {1,2,3};
    l1.push_back(8);            // добавление нового элемента в конец списка
    l1.push_front(5);           // добавление нового элемента в начало списка

    list<int> l2(10);
    l2.insert(++ ++ ++ ++ ++l2.begin(), l1.begin(), l1.end()); // вставка в список другого списка перед 5 элементом

    // deque - очередь (много памяти занимает). методы такие же как у вектора, но есть еще и push_front()
    deque d1 {1, 2, 3, 4};
    d1.push_back(2); // добавление нового элемента в конец списка
    d1.push_front(5); // добавление нового элемента в начало списка

    // set - множество (упорядоченный набор уникальных элементов); красно-черное дерево. push_back заменяется на insert
    set<int> s1 {1,2,2};   // {1, 2}
    s1.insert(5);               // добавление нового элемента в конец сета
    s1.find(1);                 //  поиск определенного элемента в сете
    s1.count(1);                // кол-во определенных элементов в сете
}