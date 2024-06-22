#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

/*

1 -> 3
2 -> 1
3 -> 1

*/

void solve(){
    int n, k; cin >> n >> k;
    vi a(k+1);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x]++;
    }

    int boxes = (n+1) / 2;
    int res = 0;
    for (int i = 1; i <= k; ++i){
        if (boxes <= 0) break;

        res += min((a[i]/2)*2, boxes*2);
        boxes -= a[i]/2;
        a[i] %= 2;
    }

    for (int i = 1; i <= k; ++i){
        if (boxes <= 0) break;
        if (a[i] == 0) continue;

        res++;
        boxes--;
    }

    cout << res << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}