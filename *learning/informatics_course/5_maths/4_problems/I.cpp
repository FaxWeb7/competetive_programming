#include <iostream>
using namespace std;

int main(){
    int a, n;
    cin >> a >> n;
    int b = (1 << n) - 1;
    cout << (b & a);

    return 0;
}