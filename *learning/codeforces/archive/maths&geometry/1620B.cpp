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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int w, h, k; cin >> w >> h;
    vvi vec(4);
    cin >> k;
    vec[0].resize(k);
    for (int &x : vec[0]) cin >> x;
    cin >> k;
    vec[1].resize(k);
    for (int &x : vec[1]) cin >> x;
    cin >> k;
    vec[2].resize(k);
    for (int &x : vec[2]) cin >> x;
    cin >> k;
    vec[3].resize(k);
    for (int &x : vec[3]) cin >> x;

    int res = 0;
    for (int i = 0; i < 4; ++i){
        res = max(res, abs(vec[i][0] - vec[i][vec[i].size()-1]) * (i < 2 ? h : w));
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
