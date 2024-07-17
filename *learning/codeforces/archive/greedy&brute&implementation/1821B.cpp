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
    vi a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    int l = -1, r = n-1;
    for (int i = 0; i < n; ++i){
        if (l == -1 && a[i] != b[i]) l = i;
        if (l != -1 && a[i] == b[i]) {
            r = i-1;
            break;
        }
    }

    while (l-1 >= 0 && b[l-1] <= b[l]) l--;
    while (r+1 < n && b[r+1] >= b[r]) r++;

    cout << l+1 << ' ' << r+1 << '\n';
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