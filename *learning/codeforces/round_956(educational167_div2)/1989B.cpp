#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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

    int lca = 0;
    for (int start = 0; start < b.size(); ++start){
        int p = start;
        for (char &x : a) {
            if (p == b.size()) break;
            if (x == b[p]) p++;
        }
        lca = max(lca, p-start);
    }

    cout << a.size() + b.size() - lca << '\n';
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