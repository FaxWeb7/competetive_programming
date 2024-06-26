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
    int n, m; cin >> n >> m;

    if (m % n != 0) {
        cout << -1 << '\n';
        return;
    }

    int res = 0;
    while (n < m){
        if (m % (3*n) == 0) n *= 3;
        else n *= 2;
        res++;
    }

    cout << (n == m ? res : -1) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}
