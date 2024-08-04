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
    int n, k; cin >> n >> k;
    vi a(n);
    int mx = 0;
    for (int &x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    bool ok = true;
    for (int &x : a){
        int Y = ((mx - x - k) + (2*k-1)) / (2*k);
        x += 2*Y*k;

        if (x < mx+k && x+k > mx) {
            mx = max(mx, x);
        } else {
            ok = false;
            break;
        }
    }
    for (int &x : a){
        if (x >= mx+k || x+k <= mx) {
            ok = false;
            break;
        }
    }

    if (ok) cout << mx << '\n';
    else cout << "-1\n";
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
