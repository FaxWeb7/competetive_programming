#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } 
    quickSort(arr, left, i-1);
    quickSort(arr, i, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    quickSort(arr, 0, n-1);
    for (int i : arr) cout << i << " ";

    return 0;
}