#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
#define int ll
const int INF = 1e5;

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        sort(all(a));
        int ans = 0;
        for (int &num : a){
            if (a[n-1] % num != 0) {
                ans = n;
                break;
            }
        }
        if (ans == n) {
            cout << n << '\n';
            continue;
        }

        cout << "h\n";
    }

    return 0;
}