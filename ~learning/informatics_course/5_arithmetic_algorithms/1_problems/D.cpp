#include <iostream>
#include <cmath>

using namespace std;

int main(){
    cout <<( unsigned long )sqrt(120);
    int n;
    cin >> n;

    for (int i = 0; i < 4; ++i){
        if (n > 0){
            int res = (unsigned long) sqrt(n);
            n = n - (unsigned long) pow(res, 2);
            cout << res << ' ';
        }
    }

    return 0;
}
