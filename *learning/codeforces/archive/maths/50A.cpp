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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    if (n == 1 || m == 1) cout << max(n, m) / 2;
    else {
        int res = max(n, m) * (min(n, m)/2);
        if (min(n, m) % 2) res += max(n, m) / 2;
        cout << res;
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}