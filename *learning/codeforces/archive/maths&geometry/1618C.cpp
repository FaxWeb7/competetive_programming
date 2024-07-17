#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

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
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    int ans1 = a[0], ans2 = a[1];
    for (int i = 0; i < n; ++i){
        if (i % 2 == 0) ans1 = gcd(ans1, a[i]);
        else ans2 = gcd(ans2, a[i]);
    }

    bool ok1 = true, ok2 = true;
    for (int i = 0; i < n; ++i){
        if (i % 2 == 1 && a[i] % ans1 == 0) ok1 = false;
        else if (i % 2 == 0 && a[i] % ans2 == 0) ok2 = false;
    }

    cout << (ok1 ? ans1 : ok2 ? ans2 : 0) << '\n';
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
