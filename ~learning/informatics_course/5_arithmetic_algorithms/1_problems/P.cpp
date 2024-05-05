#include <iostream>
#include <numeric>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    for (int y = -10000; y <= 10000; ++y){
        int ax = c - b*y;
        if (ax%a == 0 && ax + b*y == c) {
            cout << gcd(a, b) << ' ' << ax/a << ' ' << y;
            return 0;
        }
    }

    cout << "Impossible";

    return 0;
}