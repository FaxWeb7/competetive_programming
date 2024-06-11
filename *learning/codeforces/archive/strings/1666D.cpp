#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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
    string s, t; cin >> s >> t;
    map<char, int> mp;
    for (char &c : t) mp[c]++;

    int cur = t.size()-1;
    for (int i = s.size()-1; i >= 0; --i){
        if (cur >= 0 && s[i] == t[cur]){
            int cnt = 0;
            for (int j = i+1; j < s.size(); ++j){
                if (s[j] == s[i]) cnt++;
            }
            if (cnt > mp[s[i]]-1){
                cout << "NO\n";
                return;
            }
            cur--;
        }
    }

    cout << (cur == -1 ? "YES\n" : "NO\n");
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