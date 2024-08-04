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

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;

    for (int mask = 0; mask < (1 << n); ++mask){
        int sum = 0;
        for (int i = 0; i < n; ++i){
            if (mask & (1 << i)) sum += a[i];
            else sum -= a[i];
        }
        if (sum % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}