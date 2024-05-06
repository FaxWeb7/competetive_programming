// #include <iostream>
// #include <numeric>

// using namespace std;

// int main(){
//     int n, m;
//     cin >> n >> m;

//     cout << gcd(n, m);

//     return 0;
// }

#include <iostream>

using namespace std;

int gcd(int a, int b){
    while (b > 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    int n, m;
    cin >> n >> m;

    cout << gcd(n, m);

    return 0;
}