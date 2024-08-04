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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    int s = (n + 2*m) / 4;

    int ans = 0;
    for (int a = s-1; a < s+1; ++a){
        if (n < 2 * (a % 2)) continue;
        int b = (n + 2*m - 2*a) / 2;
        if (n < 2 * (a % 2 + b % 2)) b--;
        ans = max(ans, a*b);
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}