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
    int ans = true;
    
    auto check = [&](int val){
        vi b;
        for (int i = 0; i < n; ++i){
            if (a[i] != val) b.pb(a[i]);
        }
        for (int i = 0; i < b.size()/2; ++i){
            if (b[i] != b[b.size()-1-i]) return;
        }
        ans = true;
    };

    for(int i = 0; i < n/2; ++i){
        if (a[i] != a[n-1-i]) {
            ans = false;
            check(a[i]);
            check(a[n-1-i]);
            break;
        }
    }

    cout << (ans ? "YES\n" : "NO\n");
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
