#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int r, g, h; cin >> r >> g;

    // dp[i] => кол-во способов построить при помощи i красных блоков (и i-j зеленых)
    vi dp(r+1);
    dp[0] = 1;

    for (h = 1; ((1+h)*h)/2 <= r+g; ++h){
        for (int i = r; i >= h; --i){
            dp[i] = (dp[i] + dp[i-h]) % MOD;
        }
    }

    h--;
    int ans = 0;
    for (int i = 0; i <= r; ++i){
        if (((1+h)*h)/2 - i <= g){
            ans = (ans + dp[i]) % MOD;
        }
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}