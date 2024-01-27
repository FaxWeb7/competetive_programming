#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void merge(vector<ll>& arr, int left, int mid, int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
    vector<ll> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left+i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid+1+i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<ll>& arr, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

bool findItem(vector<ll>& arr, int target, int n){
    int left = 0;
    int right = n-1;
    while (left < right){
        int mid = (left+right) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid+1;
        else right = mid;
    }

    return (arr[left] == target ? true : false);
}

int main(){
    int n, m;
    cin >> n;
    vector<ll> v1(n);
    cin.ignore();
    for (int i = 0; i < n; i++) cin >> v1[i];
    cin.ignore();
    cin >> m;
    cin.ignore();
    vector<ll> v2(m);
    for (int i = 0; i < m; i++) cin >> v2[i];

    mergeSort(v1, 0, n-1);
    mergeSort(v2, 0, m-1);

    string ans = "YES";
    for (int i = 0; i < n; i++){
        if (!findItem(v2, v1[i], m)){
            ans = "NO";
            break;
        }
    }
    if (ans == "YES"){
        for (int i = 0; i < m; i++){
            if (!findItem(v1, v2[i], n)){
                ans = "NO";
                break;
            }
        }
    }
    
    cout << ans;

    return 0;
}