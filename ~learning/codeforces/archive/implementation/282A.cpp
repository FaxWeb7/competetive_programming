#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x = 0;
    for (int i = 0; i < n; ++i){
        string op;
        cin >> op;
        if (op.find('+') != -1) x++;
        else x--;
    }
    cout << x;
    return 0;
}