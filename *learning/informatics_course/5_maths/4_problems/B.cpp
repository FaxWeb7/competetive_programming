#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    cout << ((1ll << n) | (1ll << m));

    return 0;
}