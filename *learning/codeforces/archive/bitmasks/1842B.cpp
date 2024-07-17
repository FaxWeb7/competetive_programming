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
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, x; cin >> n >> x;
    vi a(n), b(n), c(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;

    if (x == 0) cout << "Yes\n";
    else {
        int ans = true;
        int pa = 0, pb = 0, pc = 0;
        int o = 0;
        for (int i = 0; i < 3*n; ++i){
            vector<pii> vec;
            if (pa < n) vec.push_back({ a[pa], 1 });
            if (pb < n) vec.push_back({ b[pb], 2 });
            if (pc < n) vec.push_back({ c[pc], 3 });
            
            pii res = {-1, -1};
            for (auto &p : vec){
                if ((x | p.F) <= x) {
                    res = p;
                }
            }

            if (res.F == -1) break;

            o |= res.F;
            if (o == x) break;

            if (res.S == 1) pa++;
            else if (res.S == 2) pb++;
            else if (res.S == 3) pc++;
        }

        cout << (o == x ? "Yes\n" : "No\n");
    }
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