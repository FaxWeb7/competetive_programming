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
    vi a(n+1);
    for (int i = 1; i <= n; ++i){
        char ch; cin >> ch;
        a[i] = ch - '0';
    }

    vi cost(n+1);
    for (int i = n; i >= 1; --i){
        for (int j = i; j <= n; j += i){
            if (a[j]) break;
            cost[j] = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (!a[i]) ans += cost[i];
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