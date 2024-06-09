#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

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
    
    map<int, int> mp;
    int maxK = -1;
    for (int i = 0; i < n; ++i){
        int num; cin >> num;
        mp[abs(num - i - 1)] = 1;
        maxK = max(maxK, abs(num - i - 1));
    }

    int res = 0;
    for (auto &p : mp){
        res = gcd(res, p.F);
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