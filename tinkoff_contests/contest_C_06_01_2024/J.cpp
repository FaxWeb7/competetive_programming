#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int binSearch(vector<int>& arr, int arrSize, int target){
    int left = 0;
    int right = arrSize-1;
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

int main(){
    int n, m;
    vector<int> v1, v2;
    v1.reserve(n);
    v2.reserve(n);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        v2.push_back(num);
    }

    int minDiff = INT_MAX;
    pair<int, int> ans;
    for (int i = 0; i < n; i++){
        int minEl = binSearch(v2, m, v1[i]);
        if (abs(v1[i]-minEl) < minDiff){
            ans.first = v1[i];
            ans.second = minEl;
            minDiff = abs(v1[i]-minEl);
        }
        if (v1[i]-minEl == 0) break;
    }

    cout << ans.first << " " << ans.second;

    return 0;
}