#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, a, b;
        cin >> n >> a >> b;

        if ((double)a < b/2.0){
            cout << n*a << '\n';
        } else {
            if (n % 2 == 0){
                cout << (n/2) * b << '\n';
            } else {
                cout << (((n-1)/2) * b) + a << '\n';
            }
        }
    }
}