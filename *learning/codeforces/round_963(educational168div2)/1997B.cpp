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
    string s; cin >> s;
    for (int i = 0; i < n; ++i) a[i] = (s[i] == 'x' ? 1 : 0);
    cin >> s;
    for (int i = 0; i < n; ++i) b[i] = (s[i] == 'x' ? 1 : 0);
    
    int ans = 0;
    for (int i = 0; i < n-2; ++i){
        if (b[i] && !b[i+1] && b[i+2] && !a[i+1]){
            if ((!a[i+2] || (i+3 < n && !b[i+3])) && (!a[i] || (i-1 >= 0 && !b[i-1]))) ans++;
        }
        if (a[i] && !a[i+1] && a[i+2] && !b[i+1]){
            if ((!b[i+2] || (i+3 < n && !a[i+3])) && (!b[i] || (i-1 >= 0 && !a[i-1]))) ans++;
        }
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