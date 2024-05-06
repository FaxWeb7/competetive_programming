// #include <iostream>
// #include <cmath>

// using namespace std;

// int main(){
//     int n;
//     cin >> n;

//     int a = pow(n, (double) 1/3);
//     int b = pow(n - pow(a, 3), (double) 1/3);
//     if (pow(a, 3) + pow(b, 3) == n) cout << a << ' ' << b;
//     else cout << "impossible";

//     return 0;
// }

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; pow(i, 3) <= n; i++) {
        for (int j = 0; pow(j, 3) <= n; j++) {
            if (pow(i, 3) + pow(j, 3) == n) {
                cout << i << " " << j;
                return 0;
            }
        }
    }

    cout << "impossible";

    return 0;
}