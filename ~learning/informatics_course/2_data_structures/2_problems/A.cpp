#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int increaseItem(vector<ll>& heap, int n, ll current, ll x){
    heap[current] += x;
    while (current > 0 && heap[current] > heap[(current-1)/2]){
        swap(heap[current], heap[(current-1)/2]);
        current = (current-1)/2;
    }
    return current+1;
}

int main(){ 
    int n;
    cin >> n;
    vector<ll> heap(n);
    for (int i = 0; i < n; i++) cin >> heap[i];

    int m;
    cin >> m;
    vector<ll> ans(m);
    for (int j = 0; j < m; j++){
        ll i, x;
        cin >> i;
        cin >> x;
        ans[j] = increaseItem(heap, n, i-1, x);
    }

    for (int i = 0; i < m; i++) cout << ans[i] << endl;
    for (int i = 0; i < n; i++) cout << heap[i] << " ";

    return 0;
}