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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    int ans = 0;
    int mode = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] == 1){
            if (mode == 0) {
                mode = 1;
                ans++;
            } else if (mode == 2) mode = 0;
        } else if (a[i] == 2){
            if (mode != 2){
                mode = 2;
                ans++;
            }
        } else {
            if (mode == 0) ans++;
            else if (mode == 1) {
                mode = 2;
                ans++;
            } else mode = 0;
        }
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}