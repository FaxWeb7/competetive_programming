#include <iostream>
using namespace std;
using ll = long long int;

bool check(ll w, ll h, ll N, ll guess){
    ll hNum = guess / h;
    ll wNum = guess / w;
    if (hNum * wNum >= N) return true;
    return false;
}

ll binSearch(ll w, ll h, ll N){
    ll left = 0;
    ll right = max(w, h)*N;
    while (left < right){
        ll mid = (left + right) / 2;
        if (check(w, h, N, mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(){
    ll w, h, N;
    cin >> w >> h >> N;

    cout << binSearch(w, h, N);

    return 0;
}
