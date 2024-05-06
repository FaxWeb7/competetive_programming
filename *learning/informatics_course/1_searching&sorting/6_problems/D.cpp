#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> countSort(vector<ll>& arr, int n){
    ll max = *max_element(begin(arr), end(arr));
    ll min = *min_element(begin(arr), end(arr));
    ll range = max - min + 1;

    vector<int> count(range);
    for (int i = 0; i < n; i++){
        count[arr[i]-min]++;
    }
    
    vector<ll> sortedArr;
    sortedArr.reserve(n);
    for (int i = 0; i < range; i++){
        for (int j = i; j < count[i]+i; j++){
            sortedArr.push_back(i+min);
        }
    }
    return sortedArr;
}

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    arr = countSort(arr, n);
    for (ll num : arr){
        cout << num << " ";
    }

    return 0;
}