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

int ceil_div(int a, int b){
    return (a + b-1) / b;
}

void solve(){
    int n, l, r; cin >> n >> l >> r;

    vi res(n);
    for (int i = 1; i <= n; ++i){
        int x1 = ceil_div(l, i) * i;
        int x2 = (r / 3) * i;

        if (x1 >= l && x1 <= r) res[i-1] = x1;
        else if (x2 >= l && x2 <= r) res[i-1] = x2;
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int &x : res) cout << x << ' ';
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