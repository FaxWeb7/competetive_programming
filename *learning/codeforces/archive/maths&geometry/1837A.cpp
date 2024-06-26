#include <iostream>
#include <algorithm>
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
    int x, k; cin >> x >> k;

    if (x % k != 0) {
        cout << 1 << '\n' << x << '\n';
    } else {
        cout << 2 << '\n' << x-1 << ' ' << 1 << '\n';
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