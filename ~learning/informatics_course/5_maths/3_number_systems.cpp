#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// перевод числа из n-ой системы счисления в 10-ричную
int toDecimal(int n, int base) {
    int res = 0;
    int power = 0;

    while (n > 0) {
        int digit = n % 10;
        res += digit * pow(base, power);
        n /= 10;
        power++;
    }

    return res;
}

// перевод числа из 10-ой системы счисления в n-ую
string fromDecimal(int n, int base) {
    string res = "";

    while (n > 0) {
        res = to_string(n % base) + res;
        n /= base;
    }

    return res;
}

int main(){
    cout << fromDecimal(100, 2);
    return 0;
}
