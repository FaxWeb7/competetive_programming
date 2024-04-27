#include <iostream>
#include <vector>
using namespace std;

vector<int> countSort(vector<int>& arr, int n) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range);
    for (int i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    vector<int> sortedArr;
    sortedArr.reserve(n);
    for (int i = 0; i < range; i++) {
        for (int j = i; j < i+count[i]; j++){
            sortedArr.push_back(i+min);
        }
    }
    return sortedArr;
}

int main() {
    int n = 4;
    vector<int> arr = {21, 15, 20, 17};
    arr = countSort(arr, n);

    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}