#include <iostream>
using namespace std;

int main(){
    int n, i;
    cin >> n >> i;

    // Установить значение бита i в 1
    cout << (n | (1ll << i));

    // Установить значение бита i в 0
    cout << (n & ~(1ll << i));

    // Определить значение бита i
    cout << (n & (1 << i));

    // Инвертировать бит i
    cout << (n ^ (1ll << i));
}