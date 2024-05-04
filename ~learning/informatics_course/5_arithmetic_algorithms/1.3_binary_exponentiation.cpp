#include <iostream>

using namespace std;

int fastBinPow(int a, int n) {
    int res = 1;

    while (n > 0) {
        if (n % 2 == 1) {
            res *= a;
        }
        a *= a;
        n /= 2;
    }

    return res;
}

int main(){
    cout << fastBinPow(2, 11) << endl;

    return 0;
}