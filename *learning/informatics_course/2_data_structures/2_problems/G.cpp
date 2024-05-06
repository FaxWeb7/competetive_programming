#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void heapify(vector<ll>& heap, int n){
    for (int i = n/2-1; i >= 0; i--){
        int current = i;
        while (2*current+1 < n){
            int maxP = (2*current+2 < n && heap[2*current+2] > heap[2*current+1]) ? 2*current+2 : 2*current+1;
            if (heap[current] < heap[maxP]) {
                swap(heap[current], heap[maxP]);
                current = maxP;
            } else break;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<ll> heap(n);
    for (int i = 0; i < n; i++) cin >> heap[i];
    heapify(heap, n);

    for (int i = 0; i < n; i++) cout << heap[i] << " ";

    return 0;
}