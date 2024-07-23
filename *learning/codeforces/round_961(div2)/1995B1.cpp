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
    int n, m; cin >> n >> m;
    vi a(n);
    for (int &x : a) cin >> x;
    sort(all(a));

    int maxLen = 0, curLen = a[0];
    for (int l = 0, r = 0; l < n; ++l){
        while (r+1 < n && a[r+1]-a[l] <= 1 && curLen + a[r+1] <= m){
            curLen += a[++r];
        }

        if (curLen <= m){
            maxLen = max(maxLen, curLen);
        }
        curLen -= a[l];
        if (l == r){
            curLen += a[++r];
        }
    }

    cout << maxLen << '\n';
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