#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

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

int maxDivider(int n){
    vector<int> res{1};
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) {
                res.push_back(n / i);
            }
        }
    }

    return *max_element(all(res));
}

void solve(){
    int n; cin >> n;

    if (n % 2 == 0) cout << n/2 << ' ' << n/2 << '\n';
    else {
        int div = maxDivider(n);
        int x = n/div;
        cout << (x-1)*div << ' ' << n - ((x-1)*div) << '\n';
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