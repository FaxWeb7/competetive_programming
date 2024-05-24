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
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int res = a[0];
        for (int i = 0; i < n-1; ++i){
            res = max(res, a[i+1]-a[i]);
        }
        res = max(res, (x-a[n-1])*2);

        cout << res << '\n';
    }

    return 0;
}