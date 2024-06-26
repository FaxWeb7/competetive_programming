#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> cnt(3, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i] % 3]++;
        }

        int target = n / 3;
        int ans = 0;

        for (int i = 0; i < 3; ++i) {
            if (cnt[i] > target) {
                int extra = cnt[i] - target;
                cnt[(i + 1) % 3] += extra;
                ans += extra;
            } else if (cnt[i] < target) {
                int need = target - cnt[i];
                ans += need;
                cnt[(i + 2) % 3] -= need;
            }
        }

        cout << ans << '\n';
    }


    return 0;
}