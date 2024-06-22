#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

void solve(){
    int n, m, y, x; cin >> n >> m >> y >> x;

    vector<pii> options = {{1,1}, {1, m}, {n, m}, {n, 1}};
    pii res = {-1, -1}; //indexes from vec options
    int maxDist = 0;
    for (int i = 0; i < 4; ++i){
        for (int j = i+1; j < 4; ++j){
            int curDist = 0;

            curDist += abs(options[i].F - y) + abs(options[i].S - x);
            curDist += abs(options[i].F - options[j].F) + abs(options[i].S - options[j].S);
            curDist += abs(options[j].F - y) + abs(options[j].S - x);

            if (curDist >= maxDist){
                maxDist = curDist;
                res = {i, j};
            }
        }
    }

    cout << options[res.F].F << ' ' << options[res.F].S << ' ' << options[res.S].F << ' ' << options[res.S].S << '\n';
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