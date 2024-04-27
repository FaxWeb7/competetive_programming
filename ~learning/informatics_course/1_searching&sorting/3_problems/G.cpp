#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<int> arr1(n*m);
    for (int i = 0; i < n*m; i++) cin >> arr1[i];
    cin >> k;
    vector<int> arr2(k);
    for (int i = 0; i < k; i++) cin >> arr2[i];
    bubbleSort(arr1, n*m);
    bubbleSort(arr2, k);

    int ans = 0;
    for (int i = 0; i < k; i++){
        for (int j = i; j < n*m; j++){
            if (arr2[i] <= arr1[j]) {
                arr1[j] = -1;
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}