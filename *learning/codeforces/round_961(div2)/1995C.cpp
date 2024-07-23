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
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    int ans = 0;
    int prev = 0;
    for (int i = 1; i < n; ++i){
        if (a[i] == 1 && a[i-1] > 1) {cout << "-1\n"; return;}

        int v1 = a[i - 1], v2 = a[i];
        int c1 = 0, c2 = 0;
        while (v2 < v1) {
            v2 *= v2;
            c2++;
        }

        while (v1 * v1 <= v2) {
            if (v1 == 1) {
                c1 = -1;
                break;
            }
            v1 *= v1;
            c1++;
        }

        if (c2) prev += c2;
        else if (c1 == -1) prev = 0;
        else prev = max(0ll, prev - c1);

        ans += prev;
    }

    cout << ans << '\n';
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