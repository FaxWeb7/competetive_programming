#include <iostream>
using namespace std;

int main(){
    int a, n;
    cin >> a >> n;
    a >>= n;
    a <<= n;
    cout << a;

    return 0;
}