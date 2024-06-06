#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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
    int n, m; cin >> n >> m;
    
    vi options;
    for (int i = (n+1) / 2; i <= n; ++i){
        if (i % m == 0) options.push_back(i);
    }

    cout << (options.size() != 0 ? options[0] : -1);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}