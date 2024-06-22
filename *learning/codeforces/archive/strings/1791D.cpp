#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    map<char, int> mp;
    // prefl[i] => кол-во уникальных символов в подстроке [0; i], prefr[i] => кол-во уникальных символов в подстроке [i; n-1]
    vi prefl(n);
    prefl[0] = 1;
    mp[s[0]]++;
    for (int i = 1; i < n; ++i){
        prefl[i] = prefl[i-1];
        if (!mp[s[i]]) {
            prefl[i]++;
            mp[s[i]]++;
        }
    }
    mp.clear();
    vi prefr(n);
    prefr[n-1] = 1;
    mp[s[n-1]]++;
    for (int i = n-2; i >= 0; --i){
        prefr[i] = prefr[i+1];
        if (!mp[s[i]]) {
            prefr[i]++;
            mp[s[i]]++;
        }
    }

    int res = 0;
    for (int i = 0; i < n-1; ++i){
        res = max(res, prefl[i] + prefr[i+1]);
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
