#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

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
const int INF = 1e9 + 7;

int ceil_div(int a, int b){
    return (a + b - 1) / b;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    
    int mx = min(m, n/k);
    int mn = ceil_div(m-mx, k-1);
    cout << max(mx - mn, 0) << '\n';
}

int32_t main(){
    unordered_map<int, int> mp;
    mp[3] = 1;
    mp.erase(3);
    cout << mp.size();
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}