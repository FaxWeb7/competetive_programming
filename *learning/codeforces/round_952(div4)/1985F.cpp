#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
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
const int EPS = -1e9;

void solve(){
    int h, n; cin >> h >> n;
    vi a(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    int l = 0, r = 1e11;
    for (int _ = 1; _ < 100; ++_){
        int mid = (l + r) / 2;

        int sum = 0;
        for (int i = 0; i < n; ++i){
            sum = min(h, sum + a[i] * ((mid + c[i] - 1) / c[i]));
        }

        if (sum == h) r = mid;
        else l = mid;
    }

    cout << r << '\n';
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