#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

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

    int ans = 2;
    for (int i = 0; pow(2, i) <= n; ++i){
        for (int j = 0; pow(2, i) * pow(3, j) <= n; ++j){
            for (int k = 0; pow(2, i) * pow(3, j) * pow(5, k) <= n; ++k){
                int x = pow(2, i) * pow(3, j) * pow(5, k);
                if (x <= n) ans = max(ans, x);
            }
        }
    }

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}