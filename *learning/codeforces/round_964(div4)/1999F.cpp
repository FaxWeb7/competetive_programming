#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 20, mod = 1e9 + 7;
int n, k, a[N], cnt[2];

inline int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

int fac[N], inv[N];

void pre() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
        inv[i] = pw(fac[i], mod - 2);
    }
}

inline int C(int n, int k) {
    if (k > n) return 0;
    return 1ll * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    pre();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int ans = 0;
        for (int t = (k + 1) / 2; t <= k; t++) {
            int res = 1ll * C(cnt[0], k - t) * C(cnt[1], t) % mod;
            ans = (ans + res) % mod;
        }
        cout << ans << '\n';
    }

}
