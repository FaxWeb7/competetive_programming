#include <iostream>
#include <vector>
using namespace std;

string isInArr(vector<int> &arr, int x);

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> arr1;
    vector<int> arr2;
    arr1.reserve(n);
    arr2.reserve(k);
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    for (int i = 0; i < k; i++){
        int num;
        cin >> num;
        arr2.push_back(num);
    }

    for (int i = 0; i < k; i++){
        cout << isInArr(arr1, arr2[i]) << endl;
    }

    return 0;
}

string isInArr(vector<int> &arr, int x){
    string ans = "NO";
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = (left + right) / 2;
        if (arr[mid] == x){
            ans = "YES";
            break;
        }
        else if (arr[mid] < x){
            left = mid + 1;
        }
        else right = mid;
    }
    if (ans == "NO" && (arr[left] == x)) ans = "YES";
    return ans;
}
