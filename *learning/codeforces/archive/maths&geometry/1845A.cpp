#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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
    int n, k, x; cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n" << n << '\n';
        for (int i = 0; i < n; ++i) cout << 1 << ' ';
        cout << '\n';
        return;
    }

    if (k == 1) cout << "NO\n";
    else if (k == 2) {
        if (n % 2 == 0){
            cout << "YES\n" << n/2 << '\n';
            for (int i = 0; i < n/2; ++i) cout << 2 << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    } else {
        if (n % 2 == 0){
            cout << "YES\n" << n/2 << '\n';
            for (int i = 0; i < n/2; ++i) cout << 2 << ' ';
            cout << '\n';
        } else {
            cout << "YES\n" << 1 + (n-=3)/2 << '\n';
            cout << 3 << ' ';
            for (int i = 0; i < n/2; ++i) cout << 2 << ' ';
            cout << '\n';
        }
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