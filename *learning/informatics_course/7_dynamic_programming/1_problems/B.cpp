#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n + 2);
    dp[n + 1] = 1;
    dp[n] = 1;
    dp[n - 1] = 2;

    for (int i = n-2; i >= 0; --i){
        dp[i] = dp[i + 1] + dp[i + 2] + dp[i + 3];
    }

    cout << dp[1];

    return 0;
}