#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;

    vvi prefa(26, vi(n+1));
    vvi prefb(26, vi(n+1));
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < 26; ++j){
            if (j == a[i-1]-'a') prefa[j][i] = prefa[j][i-1] + 1;
            else prefa[j][i] = prefa[j][i-1];

            if (j == b[i-1]-'a') prefb[j][i] = prefb[j][i-1] + 1;
            else prefb[j][i] = prefb[j][i-1];
        }
    }

    while (q--){
        int l, r; cin >> l >> r;

        int cnt = 0;
        for (int i = 0; i < 26; ++i){
            cnt += min(prefa[i][r] - prefa[i][l-1], prefb[i][r] - prefb[i][l-1]);
        }

        cout << (r-l+1) - cnt << '\n';
    }
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