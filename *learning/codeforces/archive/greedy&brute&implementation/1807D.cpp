#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

int querySum(vi &prefix, int l, int r){
    if (l-2 < 0) return prefix[r-1];
    return prefix[r-1]-prefix[l-2];
}

void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vi prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i){
        prefix[i] = prefix[i-1] + a[i];
    }

    while (q--){
        int l, r, k; cin >> l >> r >> k;
        cout << ((sum + abs(querySum(prefix, l, r) - ((r-l+1) * k))) % 2 ? "YES\n" : "NO\n");
    }
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