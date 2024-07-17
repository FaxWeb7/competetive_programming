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

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k; cin >> n >> k;
    if (k == 1) {cout << n; return 0;}

    int maxPow = 1;
    while (maxPow*2 <= n) maxPow *= 2;

    int ans = 0;
    while (maxPow > 0){
        ans += maxPow;
        maxPow /= 2;
    }
    cout << ans;

    return 0;
}
