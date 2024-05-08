#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    string ans = "";
    for (int d = 9; d >= 2; --d){
        while (n % d == 0){
            n /= d;
            ans = to_string(d) + ans;
        }
    }
    if (n == 1){
        cout << (ans.size() ? ans : "1");
    } else {
        cout << -1;
    }

    return 0;
}