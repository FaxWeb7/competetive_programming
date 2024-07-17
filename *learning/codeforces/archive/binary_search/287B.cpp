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

int ap(int n){
    return ((1 + n) * n) / 2;
}

void solve(){
    int n, k; cin >> n >> k;
    n--, k--;
    int s = ap(k);
    if (s < n) {cout << -1 << '\n'; return;}

    int l = 0, r = k;
    while (l <= r){
        int m = l + (r - l) / 2;

        if (s-ap(m) >= n) l = m+1;
        else r = m-1;
    }

    cout << k-r << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}