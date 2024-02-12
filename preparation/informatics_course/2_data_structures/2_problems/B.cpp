#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int decreaseItem(vector<ll>& heap, int n, ll current, ll x){
    heap[current] -= x;
    while (2*current+1 < n){
        int largest = current;
        int left = 2*current+1;
        int right = 2*current+2;
        if (left < n && heap[largest] < heap[left]) largest = left;
        if (right < n && heap[largest] < heap[right]) largest = right;

        if (largest != current){
            swap(heap[current], heap[largest]);
            current = largest;
        } else break;
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
    vector<int> ans(m);
    for (int j = 0; j < m; j++){
        ll i, x;
        cin >> i;
        cin >> x;

        ans[j] = decreaseItem(heap, n, i-1, x);
    }

    for (int i = 0; i < m; i++) cout << ans[i] << endl;
    for (int i = 0; i < n; i++) cout << heap[i] << " ";

    return 0;
}