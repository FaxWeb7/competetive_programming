#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
#define int ll
const int INF = 1e9;

void solve(){
    int a, b, c; cin >> a >> b >> c;

    if (a == b) cout << (c % 2 ? "First\n" : "Second\n");
    else cout << (max(a, b) == a ? "First\n" : "Second\n");
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