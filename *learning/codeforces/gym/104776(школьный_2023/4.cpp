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
    int n, p; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;
    cin >> p;

    int sum0 = 0, sum1 = 0;
    for (int i = 0; i < n; ++i){
        sum0 += a[i];
        sum1 += (n-i) * a[i];
    }

    int d = sum1 - sum0;
    cout << (p - sum0) / d;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}
