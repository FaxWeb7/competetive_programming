#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int r;
        cin >> r;

        int res = 1;
        for (int i = 0; i <= r; ++i){
            int x = sqrt(r * r - i * i);
        }

        cout << res*4 << '\n';
    }

    return 0;
}