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
    for (int i = 0; i < n; ++i) cin >> a[i];

    int res = -INF;
    for (int k = 0; k < n; ++k){
        res = max(res, a[n-1] - *min_element(a.begin(), a.begin()+k));
    }
    for (int k = 0; k < n; ++k){
        res = max(res, *max_element(a.begin()+k, a.end()) - a[0]);
    }
    for (int k = 1; k < n; ++k){
        rotate(a.begin(), a.begin()+1, a.end());
        res = max(res, a[n-1]-a[0]);
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