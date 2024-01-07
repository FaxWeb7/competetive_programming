#include <iostream>
#include <vector>
// #include <pair>
using namespace std;

pair<int, int> findEntries(vector<int> &arr, int x);

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr1;
    vector<int> arr2;
    arr1.reserve(n);
    arr2.reserve(m);
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    for (int i = 0; i < m; i++){
        int num;
        cin >> num;
        arr2.push_back(num);
    }

    for (int i = 0; i < m; i++){
        pair<int, int> ans = findEntries(arr1, arr2[i]);
        if (ans.first == 0 && (ans.second == 0)) cout << "0\n";
        else cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}

int lBinSearch(vector<int> &arr, int x){
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = (left + right) / 2;
        if (arr[mid] < x) left = mid+1;
        else right = mid;
    }
    return (arr[left] == x) ? left+1 : 0;
}

int rBinSearch(vector<int> &arr, int x){
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = (left + right + 1) / 2;
        if (arr[mid] > x) right = mid-1;
        else left = mid;
    }
    return (arr[left] == x) ? left+1 : 0;
}

pair<int, int> findEntries(vector<int> &arr, int x){
    int entry1 = lBinSearch(arr, x);
    int entry2 = rBinSearch(arr, x);
    if (entry1 == 0 && (entry2 != 0)) entry1 = entry2;
    if (entry2 == 0 && (entry1 != 0)) entry2 = entry1;

    pair<int, int> ans = {entry1, entry2};

    return ans;
}


