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
const int INF = 2*1e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    auto check = [&](int m){
        int diff = 0;
        for (int i = 0; i < n; ++i){
            diff = min(k+1, diff + max(0ll, m*a[i] - b[i]));
        }

        return diff <= k;
    };

    int l = 0, r = 2e9;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (check(m)) l = m;
        else r = m-1;
    }

    cout << l << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}