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
    int sq;

    int l = 2, r = 999;
    while (l < r){
        int mid = l + (r - l) / 2;

        cout << "? " << mid << ' ' << mid << '\n';
        cout.flush();
        cin >> sq;

        if (sq > mid * mid) r = mid;
        else l = mid + 1;
    }

    cout.flush();
    cout << "! " << l << '\n';
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