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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    vi mxa(n+n+1), mxb(n+n+1);

    int cnt = 1;
    for (int i = 0; i < n-1; ++i){
        if (a[i] != a[i+1]){
            mxa[a[i]] = max(mxa[a[i]], cnt);
            cnt = 1;
        } else cnt++;
    }
    mxa[a[n-1]] = max(mxa[a[n-1]], cnt);

    cnt = 1;
    for (int i = 0; i < n-1; ++i){
        if (b[i] != b[i+1]){
            mxb[b[i]] = max(mxb[b[i]], cnt);
            cnt = 1;
        } else cnt++;
    }
    mxb[b[n-1]] = max(mxb[b[n-1]], cnt);

    int res = 0;
    for (int i = 1; i < n+n+1; ++i) res = max(res, mxa[i]+mxb[i]);
    cout << res << '\n';
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