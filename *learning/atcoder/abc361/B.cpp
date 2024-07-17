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
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;

    if (g < d && h < e && i < f && j > a && k > b && l > c) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}