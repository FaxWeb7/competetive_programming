#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
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
const ld EPS = 1e-9;

void solve(){
    int n; cin >> n;
    vi a(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    if (!mp[1]) cout << 0 << '\n';
    else cout << (int)(mp[1] * (int)pow(2, mp[0])) << '\n';
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