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
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int guess = n-1;
    int res = a[guess];
    int prev = a[guess];
    for (int i = guess-1; i >= 0; --i){
        if (a[i] < prev){
            res += a[i];
            prev = a[i];
        } else {
            if (prev-1 >= 0) res += prev-1;
            prev -= 1;
        }
    }

    cout << res;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}