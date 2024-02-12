#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct MaxHeap{
    vector<ll> arr;
    int capacity;
    MaxHeap(int n) : capacity(n){
        arr.reserve(capacity);
    }

    void add(ll num){
        int current = arr.size();
        arr.push_back(num);

        while (current > 0 && arr[current] > arr[(current-1)/2]){
            swap(arr[current], arr[(current-1)/2]);
            current = (current-1)/2;
        }
    }
};

int main(){
    int n;
    cin >> n;

    MaxHeap heap(n);
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        heap.add(num);
    }

    for (int i = 0; i < heap.arr.size(); i++) cout << heap.arr[i] << " ";

    return 0;
}