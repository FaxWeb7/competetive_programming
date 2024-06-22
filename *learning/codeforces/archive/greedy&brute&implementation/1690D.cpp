#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int ans = INF;
    int cnt = 0;
    for (int l = 0, r = 0; l <= n-k; ++l){
        while (r-l+1 <= k) {
            if (s[r] == 'W') cnt++;
            r++;
        }

        ans = min(ans, cnt);
        if (s[l] == 'W') cnt--;
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}