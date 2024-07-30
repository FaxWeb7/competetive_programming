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
    int n; cin >> n;
    vi b(n-1);
    for (int &x : b) cin >> x;

    vi a(n);
    a[n-1] = b[n-2];
    for (int i = n-2; i >= 0; --i){
        for (int bit = 0; bit < 32; ++bit){
            if (b[i] & (1 << bit)) a[i] |= (1ll << bit);
        }
        if (i >= 1){
            for (int bit = 0; bit < 32; ++bit){
                if (b[i-1] & (1 << bit)) a[i] |= (1ll << bit);
            }
        }
        if (b[i] != (a[i] & a[i+1])) {
            cout << "-1\n";
            return;
        }
    }

    for (int &x : a) cout << x << ' ';
    cout << '\n';
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