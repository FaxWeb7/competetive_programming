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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, a, b; cin >> n >> a >> b;

    int res = 0;
    if (-a+b > 0) {
        int an = b - (min((-a+b), n)-1);
        res = ((b + an) * min((-a+b), n)) / 2;
        if ((-a+b) < n) res += (n - (-a+b)) * a;
    } else {
        res = n * a;
    }

    cout << res << '\n';
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