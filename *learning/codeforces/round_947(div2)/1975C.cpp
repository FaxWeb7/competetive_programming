#include <iostream>
#include <vector>
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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (n == 2){
            cout << *min_element(all(a)) << '\n';
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n-2; ++i){
            vector<int> triplet{a[i], a[i+1], a[i+2]};
            sort(all(triplet));
            ans = max(ans, triplet[1]);
        }

        cout << ans << '\n';
    }

    return 0;
}