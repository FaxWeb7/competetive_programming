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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int cnt = 0;
        for (int i = 0; i < n-1; ++i){
            if (a[i] > a[i+1]) {
                cnt++;
            }
        }

        bool ans = true;
        if (cnt >= 2 || cnt == 1 && a[0] < a[n-1]) ans = false;
        cout << (ans ? "Yes\n" : "No\n");
    }

    return 0;
}