#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int minGcd = gcd(a[0], a[1]);
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            minGcd = min(minGcd, gcd(a[i], a[j]));
        }
    }

    if (minGcd <= 2) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}