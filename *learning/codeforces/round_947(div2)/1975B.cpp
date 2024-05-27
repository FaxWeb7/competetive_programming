#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

        sort(all(a));
        int x1 = a[0], x2 = -1;
        for (int i = 1; i < n; ++i){
            if (a[i] % x1 != 0) {
                x2 = a[i];
                break;
            }
        }
        
        bool ans = true;
        for (int i = 0; i < n; ++i){
            if (a[i] % x1 != 0 && a[i] % x2 != 0){
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}