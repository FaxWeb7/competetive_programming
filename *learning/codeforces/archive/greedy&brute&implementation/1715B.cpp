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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, k, b, s; cin >> n >> k >> b >> s;

    if (s < k*b || s > k*b + ((k-1) * n)) cout << -1 << '\n';
    else {
        vi a(n);
        a[0] = k*b;
        s -= a[0];
        for (int i = 0; i < n; ++i){
            a[i] += min(k-1, s);
            s -= min(k-1, s);
        }

        for (int &v : a) cout << v << ' ';
        cout << '\n';
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