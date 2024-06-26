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
    int n, m, k; cin >> n >> m >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k >= m){
        cout << *max_element(all(a))*m << '\n';
        return;
    }

    sort(all(a));
    int mx1 = a[n-1];
    int mx2 = a[n-2];

    int res = (m / (k+1)) * ((mx1 * k) + mx2);
    m %= k+1;
    res += mx1 * m;

    cout << res << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}