#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct MaxHeap{
    int maxCapacity;
    vector<ll> arr;
    MaxHeap(int n){
        maxCapacity = n;
    }

    pair<int, ll> extractMax(){
        if (arr.size() == 0) return pair<int, ll>(-1, -1);

        pair<int, ll> res = {1, arr[0]};
        arr[0] = arr.back();
        arr.pop_back();
        int current = 0;
        if (arr.size() == 0) {
            res.first = -2;
            return res;
        }
        while (2*current+1 < arr.size()){
            int maxP = (arr[2*current+1] >= arr[2*current+2] ? 2*current+1 : 2*current+2);

            if (arr[current] < arr[maxP]){
                swap(arr[current], arr[maxP]);
                current = maxP;
                res.first = maxP+1;
            } else {
                break;
            }
        }
        return res;
    }

    int add(ll num){
        if (arr.size() == maxCapacity) return -1;

        int current = arr.size();
        arr.push_back(num);
        while (current > 0 && arr[(current-1)/2] < arr[current]){
            swap(arr[(current-1)/2], arr[current]);
            current = (current-1)/2;
        }
        return current+1;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    MaxHeap heap(n);
    for (int i = 0; i < m; i++){
        int command;
        cin >> command;
        if (command == 1){
            pair<int, ll> res = heap.extractMax();
            if (res.first == -1) {
                cout << -1 << endl;
            } else if (res.first == -2){
                cout << 0 << " " << res.second << endl;
            } else {
                cout << res.first << " " << res.second << endl;
            }
        } else {
            ll num;
            cin >> num;
            cout << heap.add(num) << endl;
        }
    }

    for (int i = 0; i < heap.arr.size(); i++) {
        cout << heap.arr[i] << " ";
    }

    return 0;
}