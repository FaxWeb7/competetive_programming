#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int ans = 1;
    while (a != b){
        if (a > b){
            a -= b;
        } else {
            b -= a;
        }
        ans++;
    }

    cout << ans;

    return 0;
}