#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    while (b > 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    int n;
    cin >> n;

    int maxN = 1;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int ans = nums[0];
    for (int &n : nums){
        ans = gcd(ans, n);
    }
    cout << ans;

    return 0;
}