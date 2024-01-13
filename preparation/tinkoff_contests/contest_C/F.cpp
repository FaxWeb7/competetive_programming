#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

ll fenwick[100001];
ll arr[100001];
ll pref[100001];

void increase(ll i) {
    for (; i < 100001; i = (i | (i+1)))
        fenwick[i]++;
}

ll countSum(ll i) {
    ll summa = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        summa += fenwick[i];
    return summa;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> arr[i];

    for (ll i = 1; i <= n; i++) {
        increase(arr[i]);
        pref[i] = i - countSum(arr[i]);
    }
    memset(fenwick, 0, sizeof(fenwick));

    long long ans = 0;
    for (ll i = n; i >= 1; i--) {
        increase(arr[i]);
        ans += countSum(arr[i] - 1) * pref[i] * 1LL;
    }

    cout << ans;

    return 0;
}