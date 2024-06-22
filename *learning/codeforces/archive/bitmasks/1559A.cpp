#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;
const ld EPS = 1e-9;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int x = *max_element(all(a));
    for (int i = 0; i < n; ++i){
        x &= a[i];
    }

    cout << x << '\n';
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