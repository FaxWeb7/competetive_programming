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

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        int s = 1;
        for (int i = b+1; i <= a; ++i) s *= i;

        int ans = 0;
        for (int i = 2; i * i <= s; ++i){
            while (s % i == 0) {
                s /= i;
                ans++;
            }
        }
        if (s != 1) ans++;
        cout << ans << '\n';
    }

    return 0;
}