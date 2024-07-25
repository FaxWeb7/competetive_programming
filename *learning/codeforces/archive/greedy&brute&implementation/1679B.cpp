#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

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
    int n, q; cin >> n >> q;

    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    int last2 = 0;
    map<int, int> used;
    while (q--){
        int t; cin >> t;
        if (t == 1){
            int i, x; cin >> i >> x;
            i--;

            if (!used[i]){
                used[i] = x;
                sum += x - (last2 ? last2 : a[i]);
            } else {
                sum += x - used[i];
                used[i] = x;
            }
        } else {
            int x; cin >> x;
            sum = n*x;
            last2 = x;
            used.clear();
        }
        cout << sum << '\n';
    }

    return 0;
}