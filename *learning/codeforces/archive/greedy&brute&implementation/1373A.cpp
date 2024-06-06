#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int a, b, c; cin >> a >> b >> c;

    int res1 = 0;
    if (a >= c) res1 = -1;
    else res1 = 1;

    int res2 = 0;
    if (1e9/b*c >= (1e9/b)*b*a) res2 = -1;
    else res2 = (1e9/b);

    cout << res1 << ' ' << (res2 != -1 ? res2*b : res2) << '\n';
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