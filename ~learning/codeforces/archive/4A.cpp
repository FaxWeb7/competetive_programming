#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int w;
    cin >> w;

    cout << (w % 2 || w == 2 ? "NO" : "YES");

    return 0;
}