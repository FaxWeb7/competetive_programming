#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool check(ll mid, vector<ll>& arr, int n, int k){
    ll prev = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++){
        if (arr[i] - prev >= mid){
            prev = arr[i];
            count++;
        }
    }
    return count >= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll left = 1;
    ll right = arr[n-1] - arr[0];
    while (left < right){
        ll mid = (left + right + 1) / 2;
        if (check(mid, arr, n, k)) left = mid;
        else right = mid - 1;
    }

    cout << left;


    return 0;
}