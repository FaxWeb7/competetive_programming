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
    int k; cin >> k;
    string s; cin >> s;
    if (k == 1) {
        cout << s;
        return;
    }

    map<char, int> mp;
    for (char &c : s) mp[c]++;
    bool ok = true;
    for (auto &p : mp) {
        if (p.S % k != 0) {
            ok = false;
        }
    }
    if (!ok) {
        cout << -1;
        return;
    }

    string res = "";
    for (auto &p : mp) {
        for (int i = 0; i < p.S/k; ++i){
            res += p.F;
        }
    }
    for (int i = 0; i < k; ++i) cout << res;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}