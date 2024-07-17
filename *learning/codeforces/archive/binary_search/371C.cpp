#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
// #define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2*1e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    string s; cin >> s;
    unordered_map<char, int> mp;
    for (char &ch : s) mp[ch]++;
    int nb, ns, nc; cin >> nb >> ns >> nc;
    int pb, ps, pc; cin >> pb >> ps >> pc;
    int x; cin >> x;

    auto check = [&](int m){
        int needB = max(m * mp['B'] - nb, 0ll);
        int needS = max(m * mp['S'] - ns, 0ll);
        int needC = max(m * mp['C'] - nc, 0ll);

        return pb*needB + ps*needS + pc*needC <= x;
    };

    int l = 0, r = 1e14;
    while (l < r){
        int m = l + (r - l + 1) / 2;
        if (check(m)) l = m;
        else r = m-1;
    }

    cout << l << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}