#include <iostream>
using namespace std;
using ull = unsigned long long;
using ll = long long;

bool check(ll k, ull x, ll mid);

int main(){
    ll k;
    ull x;
    cin >> k >> x;

    ll ans = -1;
    ll left = 1;
    ll right = x/(k-1);
    while (left < right){
        ll mid = (left + right) / 2;
        if (check(k, x, mid)){
            right = mid;
        } else {
            left = mid + 1;
            ans = left;
        }
    }

    cout << ans;

    return 0;
}


bool check(ll k, ull x, ll mid){
    ull sum = ((static_cast<long double>(2)*(mid+1) + (k-2))/static_cast<long double>(2))*(k-1);
    return (sum >= x);
}