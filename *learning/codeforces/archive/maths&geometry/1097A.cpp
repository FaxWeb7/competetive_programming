#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    string a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

    if (a[0] == b[0] || a[0] == c[0] || a[0] == d[0] || a[0] == e[0] || a[0] == f[0] || 
        a[1] == b[1] || a[1] == c[1] || a[1] == d[1] || a[1] == e[1] || a[1] == f[1]) cout << "YES";
    else cout << "NO";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}