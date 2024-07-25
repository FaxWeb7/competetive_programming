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
    int n, m; cin >> n >> m;
    vi a(n);
    for (int &x : a) cin >> x;
    sort(all(a));

    int ans = 0;

    int sum = 0;
    int cnt = -1;
    while (cnt+1 < n && sum + a[cnt+1] <= m) sum += a[++cnt];

    while (cnt != -1){
        int x = (m - sum) / (cnt + 1);
        ans += x+1;

        sum -= a[cnt];
        cnt--;
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