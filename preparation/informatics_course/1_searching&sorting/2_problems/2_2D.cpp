#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

ll rBinSearch(vector<ll> &arr, ll x){
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = (left + right + 1) / 2;
        if (arr[mid] >= x) right = mid - 1;
        else left = mid;
    }
    if (arr[left] >= x) return -1;
    return left;
}

ll lBinSearch(vector<ll> &arr, ll x){
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = (left + right) / 2;
        if (arr[mid] > x) right = mid;
        else left = mid + 1;
    }
    if (arr[left] <= x) return -1;
    return left;
}

pair<ll, ll> findPair(vector<ll> &arr, ll x){
    ll bj = rBinSearch(arr, x);
    ll bk = lBinSearch(arr, x);
    return pair<ll, ll> {bj, bk};
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<ll> vA;
    vector<ll> vB;
    vA.reserve(m);
    vB.reserve(n);
    for (int i = 0; i < m; i++){
        ll a;
        cin >> a;
        vA.push_back(a);
    }
    for (int i = 0; i < n; i++){
        ll b;
        cin >> b;
        vB.push_back(b);
    }
    vector<ll> vB_unsorted = vB;
    sort(vB.begin(), vB.end());

    vector<pair<ll, ll>> ans;
    for (int i = 0; i < m; i++){
        pair<ll, ll> bPair = findPair(vB, vA[i]);
        auto position1 = (bPair.first != -1 ? distance(vB_unsorted.begin(), find(vB_unsorted.begin(), vB_unsorted.end(), vB[bPair.first]))+1 : -1);
        auto position2 = (bPair.second != -1 ? distance(vB_unsorted.begin(), find(vB_unsorted.begin(), vB_unsorted.end(), vB[bPair.second]))+1 : -1);
        if (position1 != -1 && position2 != -1){
            ans.push_back(pair<ll, ll> {position1, position2});
        }
        if (i != m-2){
            vB.erase(vB.begin() + bPair.first);
            vB.erase(vB.begin() + bPair.second-1);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++){
        cout << i+1 << " " << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
