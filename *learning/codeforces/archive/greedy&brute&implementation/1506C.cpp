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

void solve(){
    string a, b; cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }

    if (a.size() > b.size()) swap(a, b);
    int lcs = 0;
    for (int l = 0; l < a.size(); ++l){
        for (int r = l; r < a.size(); ++r){
            string ta = "";
            for (int i = l; i <= r; ++i) ta += a[i];

            for (int i = 0; i < b.size()-ta.size()+1; ++i) {
                int p = 0;
                for (int j = i; j < b.size(); ++j){
                    if (b[j] == ta[p]) p++;
                    else break;

                    if (p == ta.size()) {
                        lcs = max(lcs, r-l+1);
                        break;
                    }
                }
            }
        }
    }

    cout << (a.size()-lcs) + (b.size()-lcs) << '\n';
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