#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>

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

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    vector<deque<int>> vec(51);
    for (int i = 1; i <= n; ++i){
        int color; cin >> color;
        vec[color].push_back(i);
    }

    while (q--){
        int color; cin >> color;
        int res = vec[color].front();
        cout << res << ' ';
        vec[color].front() = 1;

        for (int i = 1; i <= 50; ++i){
            for (int &val : vec[i]){
                if (i == color && val == 1) continue;
                if (val < res) val++;
                else break;
            }
        }
    }

    return 0;
}
