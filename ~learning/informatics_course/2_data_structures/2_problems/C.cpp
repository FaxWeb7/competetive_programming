#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

pair<int, ll> extractMax(vector<ll>& heap, int n){
    pair<int, ll> ans = {1, heap[0]};
    heap[0] = heap[--n];
    int current = 0;
    while (2*current+1 < n){
        int maxP = (heap[2*current+1] > heap[2*current+2] ? 2*current+1 : 2*current+2);
        if (heap[current] < heap[maxP]){
            swap(heap[current], heap[maxP]);
            current = maxP;
            ans.first = maxP+1;
        } else break;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<ll> heap(n);
    for (int i = 0; i < n; i++) cin >> heap[i];

    while (n > 1){
        pair<int, ll> ans = extractMax(heap, n--);
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}