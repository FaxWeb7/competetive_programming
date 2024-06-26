#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int x0, n; cin >> x0 >> n;

    if (x0 % 2 == 0){
        if (n % 2 == 0) {
            cout << ((n/2) % 2 == 0 ? x0 : x0+1) << '\n';
        } else {
            cout << ((n/2) % 2 == 0 ? x0-n : x0+n+1) << '\n';
        }
    } else {
        if (n % 2 == 0) {
            cout << ((n/2) % 2 == 0 ? x0 : x0-1) << '\n';
        } else {
            cout << ((n/2) % 2 == 0 ? x0+n : x0-n-1) << '\n';
        }
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