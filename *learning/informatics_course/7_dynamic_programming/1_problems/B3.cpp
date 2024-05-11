#include <iostream>
#include <vector>
using namespace std;

struct Customer{
    int a, b, c;
};

int main(){
    int n;
    cin >> n;
    vector<Customer> customers(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> customers[i].a >> customers[i].b >> customers[i].c;
    }

    // dp[i] => мин. время за которое могут быть обслужены i покупателей
    vector<int> dp(n + 2);
    dp[0] = 0, dp[1] = customers[1].a, dp[2] = min(dp[0] + customers[2-1].b, dp[1] + customers[2].a);
    for (int i = 3; i <= n; ++i){
        dp[i] = min(dp[i-3] + customers[i-2].c, min(dp[i-2] + customers[i-1].b, dp[i-1] + customers[i].a));
    }

    cout << dp[n-1];

    return 0;
}