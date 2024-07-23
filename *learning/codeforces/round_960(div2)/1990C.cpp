#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
    vi a(n), b(n);
    int ans = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        ans += a[i];
    }

    map<int, int> mp;
    int mx = 0;
    int secSum = 0;
    for (int i = 0; i < n; ++i){
        mp[a[i]]++;
        if (a[i] > mx && mp[a[i]] >= 2) mx = a[i];
        b[i] = mx;
        secSum += b[i];
    }

    cout << ans << '\n';
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