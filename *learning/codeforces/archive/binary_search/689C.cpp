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
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int m; cin >> m;

    auto check = [&](int mid){
        int k = 2;
        int ways = 0;
        while (true){
            if (mid / (k*k*k) == 0) break;
            ways += mid / (k*k*k);
            k++;
        }

        return ways >= m;
    };

    int l = 0, r = 1e18;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    int k = 2;
    int ways = 0;
    while (true){
        if (l / (k*k*k) == 0) break;
        ways += l / (k*k*k);
        k++;
    }

    cout << (ways == m ? l : -1);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}