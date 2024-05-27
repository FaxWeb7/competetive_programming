#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// расширенный алгоритм евклида
int gcd(int a, int b, int &x, int &y) {
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = x1 - (b / a) * x1;
    y = x1;

    return d;
}


int main(){
    cout << gcd(11, 121) << endl;
    cout << lcm(11, 121);

    return 0;
}