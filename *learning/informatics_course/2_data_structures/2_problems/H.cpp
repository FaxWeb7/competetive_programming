#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void heapify(vector<ll>& arr, int n, int i){
    int current = i;
    while (2*current+1 < n){
        int maxP = (2*current+2 < n && arr[2*current+2] > arr[2*current+1]) ? 2*current+2 : 2*current+1;
        if (arr[current] < arr[maxP]){
            swap(arr[current], arr[maxP]);
            current = maxP;
        } else break;
    }
}

void heapSort(vector<ll>& arr, int n){
    for (int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    heapSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}