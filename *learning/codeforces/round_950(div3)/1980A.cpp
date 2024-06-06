#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; ++i){
        char c; cin >> c;
        mp[c]++;
    }

    string s = "ABCDEFG";
    int res = 0;
    for (char c : s){
        if (mp[c] < m) res += m-mp[c];
    }

    cout << res << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}