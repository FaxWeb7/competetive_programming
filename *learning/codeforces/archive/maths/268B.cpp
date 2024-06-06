#include <iostream>
#include <algorithm>
#include <vector>

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
    int n; cin >> n;

    int res = 0;
    for (int i = 0; i < n; ++i){
        if (i == n-1) res += n;
        else res += ((n-i-1) + ((n-i-1) * i));
    }

    cout << res;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}