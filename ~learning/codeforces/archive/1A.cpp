#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m, a;
    cin >> n >> m >> a;

    long long c = ceil((double) n / a);
    long long d = ceil((double) m / a);
    cout << (long long)c * d;

    return 0;
}