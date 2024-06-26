#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
    int n, k, q; cin >> n >> k >> q;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vi vec;
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] <= q) {
            cnt++;
        } else {
            if (cnt >= k) vec.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt >= k) vec.push_back(cnt);

    int res = 0;
    for (int &v : vec){
        int quantity = 0;
        for (int i = k; i <= v; ++i) quantity += i-k+1;
        res += quantity;
    }

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