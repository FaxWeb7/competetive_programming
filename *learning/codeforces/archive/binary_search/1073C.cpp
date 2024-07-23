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
    int x, y; cin >> x >> y;
    if (n < abs(x) + abs(y) || (n - abs(x) - abs(y)) % 2) {cout << "-1\n"; return;}

    vector<pii> pref(n+1);
    pref[0] = {0, 0};

    int tx = 0, ty = 0;
    for (int i = 0; i < n; ++i){
        pref[i+1] = pref[i];
        if (s[i] == 'U') pref[i+1].S++;
        else if (s[i] == 'D') pref[i+1].S--;
        else if (s[i] == 'L') pref[i+1].F--;
        else if (s[i] == 'R') pref[i+1].F++;
    }

    auto check = [&](int mid){
        for (int l = 0; l <= n-mid; ++l){
            int nx = pref[n].F - (pref[l+mid].F - pref[l].F);
            int ny = pref[n].S - (pref[l+mid].S - pref[l].S);

            int temp = mid;
            if (nx > x || nx < x) temp -= abs(nx-x);
            if (ny > y || ny < y) temp -= abs(ny-y);

            if (temp >= 0 && temp % 2 == 0) return true;
        }

        return false;
    };

    int l = 0, r = n;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid+1;
    }

    cout << l << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}