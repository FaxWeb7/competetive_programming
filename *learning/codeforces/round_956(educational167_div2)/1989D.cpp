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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vi a(n), c(m);
    map<int, int> mpa;

    for (int &x : a) cin >> x;
    for (int i = 0; i < n; ++i) {
        int bi; cin >> bi;
        mpa[a[i]-bi] = a[i];
    }
    for (int &x : c) cin >> x;

    int ans = 0;
    for (int &money : c){
        for (auto &p : mpa){
            int d = money - p.S + 1;
            if (d > 0) {
                money -= ceil((double)d/p.F)*p.F;
                ans += ceil((double)d/p.F)*2;
            }
        }
    }

    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}