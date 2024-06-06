#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    map<char, int> mp;
    for (char &c : s) mp[c]++;

    int odd = 0;
    for (auto &p : mp) {
        if (p.S % 2) odd++;
    }

    cout << (odd <= k+1 ? "YES\n" : "NO\n");
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