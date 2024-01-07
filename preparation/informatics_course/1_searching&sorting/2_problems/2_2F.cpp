#include <iostream>
#include <cmath>
using ll = long long int;
using namespace std;

int main(){
    ll N;
    double x, y;
    cin >> N >> x >> y;
    
    ll left = 0;
    ll right = min(x, y) * N;
    while (left < right){
        ll mid = (left + right) / 2;
        if ((1.0 + (floor((mid-min(x, y))/x) + floor(mid-min(x, y))/y)) >= N) right = mid;
        else left = mid + 1;
    }
    cout << left;

    return 0;
}