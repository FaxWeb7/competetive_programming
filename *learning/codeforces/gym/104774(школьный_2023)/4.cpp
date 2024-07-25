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
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;

    int ans = 0;
    for (int i = 1; i != m%10; ++i){
        string num = "";
        for (int j = 0; j < to_string(n).size(); ++j) num += to_string(i);

        if (stoi(num) <= n) ans += num.size();
        else ans += num.size()-1;
    }
    ans += to_string(m).size();

    cout << ans;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}