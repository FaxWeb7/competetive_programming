#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

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
    string s; cin >> s;

    unordered_map<char, int> mp;
    string pattern = "";
    int p = -1;
    bool ans = true;
    for (int i = 0; i < s.size(); ++i){
        if (!mp[s[i]] && p == -1) {
            pattern += s[i];
            mp[s[i]]++;
        }
        else {
            if (p == -1) p = 0;
            
            if (s[i] != pattern[p]) ans = false;
            p = (p+1) % sz(pattern);
        }
    }

    cout << (ans ? "YES\n" : "NO\n");
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