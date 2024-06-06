#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n % 2 == 0){
        cout << 2 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n << '\n';
    } else {
        cout << 4 << '\n';
        cout << 1 << ' ' << n-1 << '\n';
        cout << 1 << ' ' << n-1 << '\n';
        cout << n-1 << ' ' << n << '\n';
        cout << n-1 << ' ' << n << '\n';
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