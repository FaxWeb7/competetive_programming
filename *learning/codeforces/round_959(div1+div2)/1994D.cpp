#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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

    map<int, vector<pii>> mp;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            mp[abs(a[i]-a[j])].pb({i+1, j+1});
        }
    }

    vector<pii> res(n-1);
    for (int i = n-1; i >= 1; --i){
        bool ok = false;
        for (auto &p : mp){
            if (p.F % i == 0 && p.S.size() > 0){
                res[i-1] = {p.S.back().F, p.S.back().S};
                p.S.pop_back();
                ok = true;
                break;
            }
        }
        if (!ok){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (pii &p : res) cout << p.F << ' ' << p.S << '\n';
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