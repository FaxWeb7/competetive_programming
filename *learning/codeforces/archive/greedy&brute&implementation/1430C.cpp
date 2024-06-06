#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

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

    cout << 2 << '\n';
    vi a(n);
    for (int i = 1; i <= n; ++i) a[i-1] = i;
    for (int i = n-1; i > 0; --i){
        cout << a[a.size()-1] << ' ' << a[a.size()-2] << '\n';
        int val = ceil((a[a.size()-1] + a[a.size()-2]) / 2.0);
        a.pop_back(); a.pop_back(); a.push_back(val);
    }
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