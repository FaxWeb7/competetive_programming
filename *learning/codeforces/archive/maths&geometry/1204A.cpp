#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    string s; cin >> s;

    if (s == "0" || s == "1") cout << 0 << '\n';
    else {
        int cnt = (sz(s)-1) / 2;
        if ((sz(s)-1) % 2 == 0 && count(all(s), '1') == 1) cnt--;

        cout << cnt + 1 << '\n';
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}