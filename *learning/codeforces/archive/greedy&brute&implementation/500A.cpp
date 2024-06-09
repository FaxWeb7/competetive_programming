#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
// #define int ll
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
    int n, t; cin >> n >> t;
    vi a(n+1);
    for (int i = 1; i < n; ++i) cin >> a[i];

    int cur = 1;
    while (cur < n){
        if (cur == t) {
            cout << "YES";
            return;
        }
        cur += a[cur];
    }
    cout << (cur == t ? "YES" : "NO");
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}
