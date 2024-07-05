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
const int INF = 1e9 + 7;

int maxSubarraySum(vi &a, int n, int l, int r){
    int maxSum = a[l], curSum = 0;
    for (int i = l; i <= r; ++i){
        curSum += a[i];
        maxSum = max(maxSum, curSum);
        if (curSum < 0) curSum = 0;
    }

    return maxSum;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    int ans = *max_element(all(a));
    int l = 0;
    for (int r = 0; r < n; ++r){
        while (r+1 < n && abs(a[r+1]) % 2 != abs(a[r]) % 2) ++r;

        if (r != l) ans = max(ans, maxSubarraySum(a, n, l, r));
        l = r+1;
    }

    cout << ans << '\n';
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