#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    // if (left < j) quickSort(arr, left, i-1);
    // if (right >= i) quickSort(arr, i, right);
    quickSort(arr, left, i-1);
    quickSort(arr, i, right);
}



int main(){
    vector<int> arr = {4,7,2,5,9,4,3};
    quickSort(arr, 0, arr.size()-1);
    for(int num : arr) {
        cout << num << " ";
    }

    return 0;
}