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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int n; cin >> n;
    if (n/2 % 2) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 2; i <= n; i += 2) cout << i << ' ';
        for (int i = 1; i <= n-1; i += 2) {
            if (i == n-1) cout << n-1 + n/2 << ' ';
            else cout << i << ' ';
        }
        cout << '\n';
    }
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