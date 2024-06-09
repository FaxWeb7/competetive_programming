#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
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

void solve(){
    int n, x, y; cin >> n >> x >> y;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int g = 0; g < n; ++g){
        bool ok = true;
        for (int i = g-1; i >= 0 && i >= g-x; --i) {
            if (a[i] < a[g]) ok = false;
        }
        for (int i = g+1; i < n && i <= g+y; ++i){
            if (a[i] < a[g]) ok = false;
        }

        if (ok){
            cout << g+1;
            return;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}