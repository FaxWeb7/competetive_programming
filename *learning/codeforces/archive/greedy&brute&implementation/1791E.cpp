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

    bool hasZero = false;
    int cntNeg = 0;
    int minNum = INF;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        sum += abs(x);
        minNum = min(minNum, abs(x));
        if (x == 0) hasZero = true;
        if (x < 0) {
            cntNeg++;
        }
    }

    if (cntNeg % 2 == 0 || hasZero) cout << sum << '\n';
    else cout << sum - 2*minNum << '\n';
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