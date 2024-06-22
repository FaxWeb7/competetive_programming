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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int startY = 0, finishY = 0, startX = 0, finishX = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (a[i][j] == '#') {
                if (startY == 0) startY = i+1;
                finishY = i+1;
            }

            if (a[i][j] == '#'){
                if (startX == 0 || startX > j+1) startX = j+1;
                if (finishX == 0 || finishX < j+1) finishX = j+1;
            }
        }
    }

    cout << (startY + finishY + 1) / 2 << ' ' << (startX + finishX + 1) / 2 << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}