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
    int n, k; cin >> n >> k;
    vi a(n);
    for (int &x : a) cin >> x;
    if (k == 1) {cout << 0; return;}

    sort(all(a));

    int minWeak = INF, curWeak = 0;
    for (int l = 0, r = 0; l < n-k+1; ++l){
        while (r-l+1 < k) {
            ++r;
            curWeak += a[r] - a[r-1];
        }

        minWeak = min(minWeak, curWeak);
        curWeak -= a[l+1]-a[l];
    }

    cout << minWeak;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}