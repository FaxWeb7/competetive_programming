#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){ 
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    long double res = 0.0;
    while (n != 1){
        vector<long long> newArr;
        for (int i = 0; i <= n/2; i+=2){
            res += 0.05*(arr[i]+arr[i+1]);
            newArr.push_back(arr[i]+arr[i+1]);
        }
        if (n%2 != 0) newArr.push_back(arr[n-1]);
        n = (n+1)/2;
        arr = newArr;
        sort(arr.begin(), arr.end());
    }

    cout << fixed << setprecision(2) << res;

    return 0;
}