
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    vi a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]] = i;
    }

    int power = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < mp[a[i]]; ++j){
            if (mp[a[j]] > mp[a[i]]) i = j;
        }
        i = mp[a[i]];
        power++;
    }

    int ans = 1;
    for (int i = 1; i < power; ++i){
        ans = (ans * 2) % MOD;
    }
    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}