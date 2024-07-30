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
    int n; cin >> n;
    string s; cin >> s;

    unordered_map<int, int> mp;
    for (char &ch : s) mp[ch - 'a']++;

    int ans = INF;
    for (int i = 0; i < 26; ++i){
        int l = 0, r = n-1;
        bool ok = true;
        while (l < r){
            if (s[l] - 'a' == i) l++;
            else if (s[r] - 'a' == i) r--;
            else {
                if (s[l] != s[r]) ok = false;
                l++, r--;
            }
        }

        if (ok) {
            int curAns = 0;
            int l = 0, r = n-1;
            while (l < r){
                if (s[l] - 'a' == i && s[r] - 'a' == i) l++, r--;
                else if (s[l] - 'a' == i) {
                    l++;
                    curAns++;
                }
                else if (s[r] - 'a' == i) {
                    r--;
                    curAns++;
                }
                else l++, r--;
            }

            ans = min(ans, curAns);
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
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
