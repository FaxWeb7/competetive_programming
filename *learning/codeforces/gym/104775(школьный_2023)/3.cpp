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
    int n, m, s; cin >> n >> m >> s;

    int ans = 1;
    for (int a = 1; a <= min(s, (ll)1e6); ++a){
        if (s % a) continue;

        int b = s/a;
        int op1 = (n/a) * (m/b);
        int op2 = (n/b) * (m/a);
        ans = max(ans, max(op1, op2));
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}