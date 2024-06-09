#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
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

void solve(){
    int n; cin >> n;
    vi k(n);
    int kLcm = 1;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        kLcm = lcm(kLcm, k[i]);
    }

    double cnt = 0;
    for (int i = 0; i < n; ++i){
        cnt += kLcm / k[i];
    }
    if (cnt/kLcm >= 1.0){
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; ++i){
        cout << (int) ceil((1.0 / k[i]) * 1e8) << ' ';
    }
    cout << '\n';
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