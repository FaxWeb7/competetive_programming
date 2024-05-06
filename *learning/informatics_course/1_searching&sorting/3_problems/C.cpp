#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k, m;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k >> m;
    arr[n] = k;

    for (int i = n; i >= m; --i){
        arr[i] = arr[i-1];
    }
    arr[m-1] = k;
    for (int i = 0; i <= n; i++) cout << arr[i] << " ";

    return 0;
}