#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

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
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n), b(n), pref(n + 1);
    unordered_map<int, vi> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].pb(i);
    }

    sort(all(a));
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1] + a[i-1];
    }

    for (int i = n-1; i >= 0; --i){
        int res = i;
        if (i+1 < n && pref[i+1] >= a[i+1]) res += b[mp[a[i+1]][0]] - i;

        for (int &idx : mp[a[i]]){
            b[idx] = res;
        }
        int x = mp[a[i]][0];
        mp[a[i]].clear();
        mp[a[i]].pb(x);
    }

    for (int &x : b) cout << x << ' ';
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