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
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int x, y, z; cin >> x >> y >> z;

    if ((x == y && x >= z) || (x == z && x >= y) || y == z && y >= x) cout << "YES\n" << max(x,y,z) << ' ' << min(x,y,z) << ' ' << min(x,y,z) << '\n';
    else cout << "NO\n";
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