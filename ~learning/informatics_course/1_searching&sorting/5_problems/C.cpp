#include <iostream>
#include <vector>
using namespace std;

int extractMin(vector<int> arr, int n, int i, int k){
    int current = 0;
    while (2*current+1 < k){
        int minP = (2*current+2 < k && arr[2*current+2+i] < arr[2*current+1+i]) ? 2*current+2 : 2*current+1;
        if (arr[current+i] > arr[minP+i]){
            swap(arr[current+i], arr[minP+i]);
            current = minP;
        } else break;
    }
    return arr[i];
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans(n-k+1);
    for (int i = 0; i < n-k+1; i++){
        int min = extractMin(arr, n, i, k);
        ans[i] = min;
    }

    for (int num : ans) cout << num << endl;

    return 0;
}