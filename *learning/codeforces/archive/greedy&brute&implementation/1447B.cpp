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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

vi dy = {1, 0, -1, 0};
vi dx = {0, 1, 0, -1};

void solve(){
    int n, m; cin >> n >> m;
    vi a(n*m);
    int sum = 0, cnt = 0, mn = INF;
    for (int i = 0; i < n*m; ++i){
        int x; cin >> x;
        if (x < 0) cnt++;
        sum += abs(x);
        mn = min(mn, abs(x));
    }

    if (cnt % 2 == 0) cout << sum << '\n';
    else cout << sum - 2*mn << '\n';
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