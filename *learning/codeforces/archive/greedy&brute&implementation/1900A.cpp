#include <iostream>
#include <vector>
#include <set>
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


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;

        int maxCells = 0;
        int cntCells = 0;
        int res = 0;
        for (int i = 0; i < n; ++i){
            if (s[i] == '.'){
                cntCells++;
                maxCells = max(maxCells, cntCells);
            } else {
                res += cntCells;
                cntCells = 0;
            }
        }

        if (maxCells >= 3) {
            cout << 2 << '\n';
            continue;
        }

        cout << res+cntCells << '\n';
    }

    return 0;
}