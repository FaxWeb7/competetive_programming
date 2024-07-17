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
    int n, k; cin >> n >> k;
    vi c(n);
    unordered_map<int, pair<int, pii>> prevIdx; // {prevIdx, {maxHop1, maxHop2}}
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (prevIdx.find(c[i]) == prevIdx.end()) prevIdx[c[i]] = {-1, {-1, -1}};
        if (i-prevIdx[c[i]].F-1 > prevIdx[c[i]].S.F){
            prevIdx[c[i]].S.S = prevIdx[c[i]].S.F;
            prevIdx[c[i]].S.F = i-prevIdx[c[i]].F-1;
        } else prevIdx[c[i]].S.S = max(prevIdx[c[i]].S.S, i-prevIdx[c[i]].F-1);
        prevIdx[c[i]].F = i;
    }

    int minDiff = INF;
    for (int i = 0; i < n; ++i){
        if (n-prevIdx[c[i]].F-1 > prevIdx[c[i]].S.F){
            prevIdx[c[i]].S.S = prevIdx[c[i]].S.F;
            prevIdx[c[i]].S.F = n-prevIdx[c[i]].F-1;
        } else prevIdx[c[i]].S.S = max(prevIdx[c[i]].S.S, n-prevIdx[c[i]].F-1);
        minDiff = min(minDiff, max(prevIdx[c[i]].S.F/2, prevIdx[c[i]].S.S));
    }

    cout << minDiff << '\n';
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