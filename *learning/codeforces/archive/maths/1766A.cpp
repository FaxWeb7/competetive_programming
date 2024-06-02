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
    int n; cin >> n;

    int res = 0;
    while (n > 9) {
        res += 9;
        n = stoi(to_string(n).substr(0, to_string(n).length()-1));
    }
    res += n;

    cout << res << '\n';
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