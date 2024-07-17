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
const int INF = 1e18 + 7;

void solve(){
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<pii> vec(n);
    for (auto &[x, y] : vec) cin >> x >> y;

    if (a <= k && b <= k) {
        cout << 0 << '\n';
        return;
    }

    int distFrom = INF;
    int distTo = INF;
    for (int i = 0; i < k; ++i){
        if (i != a) {
            distFrom = min(distFrom, abs(vec[a-1].F - vec[i].F) + abs(vec[a-1].S - vec[i].S));
        }
        if (i != b){
            distTo = min(distTo, abs(vec[b-1].F - vec[i].F) + abs(vec[b-1].S - vec[i].S));
        }
    }
    if (a <= k) distFrom = 0;
    if (b <= k) distTo = 0;

    int option1 = abs(vec[a-1].F - vec[b-1].F) + abs(vec[a-1].S - vec[b-1].S);
    int option2 = distFrom+distTo;
    cout << min(option1, option2) << '\n';
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