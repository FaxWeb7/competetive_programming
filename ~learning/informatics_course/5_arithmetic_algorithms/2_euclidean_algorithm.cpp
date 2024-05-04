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

int main(){
    cout << gcd(11, 121) << endl;
    cout << lcm(11, 121);

    return 0;
}