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
#define rall(x) x.rbegin(), x.rend()
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
    vector<vector<pii>> a(3, vector<pii>(n)); // {val, idx}
    for (int i = 0; i < n; ++i){
        cin >> a[0][i].F;
        a[0][i].S = i;
    }
    for (int i = 0; i < n; ++i){
        cin >> a[1][i].F;
        a[1][i].S = i;
    }
    for (int i = 0; i < n; ++i){
        cin >> a[2][i].F;
        a[2][i].S = i;
    }
    sort(rall(a[0])), sort(rall(a[1])), sort(rall(a[2]));

    int ans = 0;
    for (int k = 0; k < 3; ++k){
        int mx1 = a[k][0].F, mx2 = 0, mx3 = 0;

        for (int i = 0; i < 3; ++i){
            if (i == k) continue;
            mx2 = (a[i][0].S != a[k][0].S ? a[i][0].F : a[i][1].F);
            int mx2Idx = (a[i][0].S != a[k][0].S ? a[i][0].S : a[i][1].S);

            int j = ((i+1)%3 != k ? (i+1)%3 : (i+2)%3);
            if (a[k][0].S != a[j][0].S && mx2Idx != a[j][0].S) mx3 = a[j][0].F;
            else if (a[k][0].S != a[j][1].S && mx2Idx != a[j][1].S) mx3 = a[j][1].F;
            else mx3 = a[j][2].F;

            ans = max(ans, mx1+mx2+mx3);
        }
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