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
    int n; cin >> n;
    vi a(n);
    map<int, int> mp;
    int maxV = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxV = max(maxV, ++mp[a[i]]);
    }

    int curSz = n-maxV;
    int res = 0;
    while (curSz > 0){
        res++;
        for (int i = 0; i < maxV && curSz > 0; ++i){
            curSz -= 1;
            res += 1;
        }
        maxV *= 2;
    }

    cout << res << '\n';
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