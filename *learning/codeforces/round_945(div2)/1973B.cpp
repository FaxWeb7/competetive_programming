#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;


int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vll a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int ans = 1;
        for (int bit = 0; bit < 20; ++bit){
            int cur = 0, cnt = 0;
            for (int i = 0; i < n; ++i){
                if (1 << bit & a[i]){
                    cnt = 0;
                }
                else{
                    cnt++;
                }
                cur = max(cur, cnt);
            }

            if (cnt != n){
                ans = max(ans, 1 + cur);
            }
        }
        
        cout << ans << '\n';
        }

    return 0;
}