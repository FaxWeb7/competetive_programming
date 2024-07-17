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
    vector<pii> a(n);
    int mn = 0, mx = 0;
    for (auto &[l, r] : a){
        cin >> l >> r;
        mn += l, mx += r;
    }

    if (mn <= 0 && mx >= 0) {
        cout << "Yes\n";
        for (auto &[l, r] : a){
            if (mx > 0) {
                cout << (mx < abs(r-l) ? (r-mx) : l) << ' ';
                mx -= min(mx, abs(r-l));
            }
            else cout << r << ' ';
        }
        cout << '\n';
    }
    else cout << "No\n";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}