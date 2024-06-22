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
const double EPS = 1e-10;
const int INF = 1e9 + 7;


void solve(){
    int n, k; cin >> n >> k;
    vi a(n);

    bool was = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % k == 0) was = true;
    }
    if (was) {
        cout << 0 << '\n';
        return;
    }

    int nearestRem = k-1;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        nearestRem = min(nearestRem, k - (a[i] % k));
        if (a[i] % k == 1) cnt1++;
        if (a[i] % k == 2) cnt2++;
    }
    if (k == 4) cout << min(nearestRem, (cnt2 >= 2 ? 0 : cnt2 == 1 && cnt1 >= 1 ? 1 : cnt1 >= 2 ? 2 : 3)) << '\n';
    else cout << nearestRem << '\n';
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