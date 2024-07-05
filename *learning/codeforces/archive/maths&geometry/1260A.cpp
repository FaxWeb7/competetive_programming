#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
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
    int c, sum; cin >> c >> sum;

    if (c >= sum) cout << sum << '\n';
    else if (c == 1) cout << sum*sum << '\n';
    else {
        vi a(c, 1);

        int cost = c, curSum = c;
        int k = c-1;
        while (curSum < sum) {
            curSum++;
            cost -= a[k]*a[k];
            a[k]++;
            cost += a[k]*a[k];

            k--;
            if (k == -1) k = c-1;
        }

        cout << cost << '\n';
    }
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