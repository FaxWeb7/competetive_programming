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
    int n; cin >> n;
    vi a(n), b(n), c;
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] == b[i] && a[i] != 0) c.pb(a[i]);
        else if (a[i] > b[i]) res1 += a[i];
        else res2 += b[i];
    }

    for (int &x : c) {
        if (res1 < res2) {
            if (x == 1) res1++;
            else res2--;
        } else {
            if (x == 1) res2++;
            else res1--;
        }
    }

    cout << min(res1, res2) << '\n';
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