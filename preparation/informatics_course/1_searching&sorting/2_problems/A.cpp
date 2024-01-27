#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int binSearch(vector<int> &arr, int target);

int main(){
    int n, k;
    cin >> n >> k;
    cin.ignore();

    vector<int> arr1;
    vector<int> arr2;
    arr1.reserve(n);
    arr2.reserve(k);

    for (int i = 0; i < n; i++){
        int el;
        cin >> el;
        arr1.push_back(el);
    }
    for (int i = 0; i < k; i++){
        int el;
        cin >> el;
        arr2.push_back(el);
    }

    for (int i = 0; i < k; i++){
        cout << binSearch(arr1, arr2[i]) << endl;
    }

    return 0;
}

int binSearch(vector<int> &arr, int target){
    int left = 0;
    int right = arr.size()-1;
    int closest = arr[0];
    while (left <= right) {
        int mid = (left+right) / 2;
        if (arr[mid] == target) {
            closest = arr[mid];
            break;
        } else if (arr[mid] < target) {
            closest = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (abs(arr[left] - target) < abs(target - closest)) {
        closest = arr[left];
    }
    return closest;
}