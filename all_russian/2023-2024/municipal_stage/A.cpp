#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    if (n <= 6) cout << 1;
    else cout << 1 + ceil((n - 6) / 4.0);

    return 0;
}