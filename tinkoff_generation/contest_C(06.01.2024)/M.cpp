#include <iostream>
#include <vector>
using namespace std;

bool findItem(vector<int>& arr, int arrSize, int target);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int> &arr, int low, int high);
void swap(int &a, int &b);

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    quickSort(b, 0, m-1);
    int ans = 1303;
    for (int i = 0; i < n; i++){
        if (!findItem(b, m, a[i])){
            ans = 179;
        }
    }

    cout << ans;

    return 0;
}

bool findItem(vector<int>& arr, int arrSize, int target){
    int left = 0;
    int right = arrSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return false; 
}

void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
