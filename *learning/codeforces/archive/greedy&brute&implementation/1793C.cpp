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

    int l = 0, r = n-1;
    int mn = 1, mx = n;
    while (l < r){
        if (a[l] == mn ) {
            l++;
            mn++;
        } else if (a[l] == mx){
            l++;
            mx--;
        } else if (a[r] == mn) {
            r--;
            mn++;
        } else if (a[r] == mx){
            r--;
            mx--;
        } else {
            cout << l+1 << ' ' << r+1 << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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