#include <iostream>
using namespace std;

int main(){
    int a;
    cin >> a;

    for (int i = 7; i >= 0; --i){
        cout << ((a >> i) & 1);
    }

    return 0;
}