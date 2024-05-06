#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int middle, int right) {
    //разбиение массива на [left, mid] и [mid+1, right]
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    //слияние двух массивов
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}


int main(){
    int n = 6;
    vector<int> arr {5, 3, 7, 2, 8, 1};

    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) cout << arr[i];


    return 0;
}