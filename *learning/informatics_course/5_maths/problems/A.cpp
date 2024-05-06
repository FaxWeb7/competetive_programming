#include <iostream>

using namespace std;

void sol(int &a, int &b){
    for (int i = 2; i * i <= max(a, b); ++i){
        while (a % i == 0 && b % i == 0){
            a /= i;
            b /= i;
        }
    }
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int e = (a * d) + (c * b);
    int f = b * d;
    sol(e, f);
    cout << e << ' ' << f;

    return 0;
}