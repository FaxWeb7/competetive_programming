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
#define sz(x) (int)a.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

vvi segments{
    {1, 2, 4, 6, 8, 9},
    {3, 4, 8},
    {1, 4, 7, 9},
    {1, 3, 5, 7},
    {2, 4, 5, 8},
    {1, 2, 5, 8, 9},
    {3, 5, 6, 8, 9},
    {1, 3, 6},
    {1, 2, 4, 5, 6, 8, 9},
    {1, 2, 4, 5, 7}
};

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    vi ans;
    for (int i = 0; i < 10; ++i){
        if (find(all(a), i) != a.end()) {
            ans.pb(i);
            continue;
        }

        vi b(10);
        for (int &x : segments[i]) b[x] = 1;

        for (int &x : a){
            for (int &y : segments[x]){
                b[y] = 0;
            }
        }

        if (find(all(b), 1) == b.end()) ans.pb(i);
    }

    for (int &x : ans) cout << x << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}