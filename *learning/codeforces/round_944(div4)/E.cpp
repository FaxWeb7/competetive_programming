#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define all(x) x.begin(), x.end()

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, k, q;
        cin >> n >> k >> q;
        vi a(k + 1), b(k + 1);
        for (int i = 1; i <= k; ++i) cin >> a[i];
        for (int i = 1; i <= k; ++i) cin >> b[i];

        while (q--){
            ll d;
            cin >> d;
            int idx = lower_bound(all(a), d) - a.begin();

            if (a[idx] == d){
                cout << b[idx] << ' ';
            } else {
                idx--;
                ll ans = b[idx] + ((b[idx+1]-b[idx]) * (d-a[idx]))/(a[idx+1]-a[idx]);
                cout << ans << ' ';
            }
        }

        cout << '\n';
    }
    
    return 0;
}