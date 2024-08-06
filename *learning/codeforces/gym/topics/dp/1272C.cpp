#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    unordered_map<char, int> mp;
    for (int i = 0; i < k; ++i){
        char ch; cin >> ch;
        mp[ch] = 1;
    }

    vi dp(n);
    dp[0] = mp[s[0]];

    int ans = 0;
    for (int i = 1; i < n; ++i){
        if (!mp[s[i]]) {
            ans += (dp[i-1] * (dp[i-1]+1)) / 2;
        } else {
            dp[i] = dp[i-1] + 1;
        }
    }
    ans += (dp[n-1] * (dp[n-1]+1)) / 2;

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}