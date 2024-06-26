#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

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
    int n, k, x; cin >> n >> k >> x;

    int sumTop = ((n-k+1 + n)*k)/2;
    int sumBottom = ((1 + k)*k)/2;

    cout << (sumTop >= x && sumBottom <= x ? "YES\n" : "NO\n");
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