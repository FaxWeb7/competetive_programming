#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e7;
const int MOD = 1e9 + 7;

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            result.push_back(i);
        }
    }
    return result;
}
vector<int> primes = sieve_of_eratosthenes(sqrt(1e7)-1);

int mylg(int x, int y) {
    return log(x) / log(y);
}

void pbVals(vi &a, int x, int power){
    if (power == 1) {a.pb(x); return;}
    if (power <= 7*mylg(10, x)){
        a.pb(pow(x, power));
        return;
    }
    pbVals(a, x, power/2);
    pbVals(a, x, power-power/2);
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;

    unordered_map<int, int> st;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        st[x]++;
    }
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        st[x]--;
    }

    for (pii p : st){
        for (int prime : primes) {
            if (prime*prime > p.F) break;
            while (p.F % prime == 0) {
                mp[prime] += p.S;
                p.F /= prime;
            }
        }
        if (p.F > 1) mp[p.F] += p.S;
    }

    for (int i = 0; i < 10; ++i){
        for (auto &p : mp){
            if (p.S > 0) {
                if (p.S <= 7*mylg(10, p.F) && pow(p.F, p.S) != p.F){
                    mp[pow(p.F, p.S)] = 1;
                    mp[p.F] = 0;
                }
            } else if (p.S < 0){
                if (-p.S <= 7*mylg(10, p.F) && pow(p.F, -p.S) != p.F){
                    mp[pow(p.F, -p.S)] = -1;
                    mp[p.F] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 100; ++i){
        for (pii p : mp){
            if (p.S > 0) {
                int t = 1, k = p.F;
                pair<pii, int> mn = {{0, 1}, p.S};
                while (k*p.F <= 1e7) {
                    t++; k*=p.F;
                    if (mn.F.F+mn.S > p.S/t+p.S%t) mn = {{p.S/t, k}, p.S%t};
                }
                mp[mn.F.S] = mn.F.F;
                mp[p.F] = mn.S;
            } else if (p.S < 0){
                p.S = -p.S;
                int t = 1, k = p.F;
                pair<pii, int> mn = {{0, 1}, p.S};
                while (k*p.F <= 1e7) {
                    t++; k*=p.F;
                    if (mn.F.F+mn.S > p.S/t+p.S%t) mn = {{p.S/t, k}, p.S%t};
                }
                mp[mn.F.S] = -mn.F.F;
                mp[p.F] = -mn.S;
            }
        }
    }
    mp[1] = 0;
    vi a, b;
    for (pii p : mp){
        if (p.S > 0) {
            int t = 1, k = p.F;
            pair<pii, int> mn = {{0, 1}, p.S};
            while (k*p.F <= 1e7) {
                t++; k*=p.F;
                if (mn.F.F+mn.S > p.S/t+p.S%t) mn = {{p.S/t, k}, p.S%t};
            }
            for (int i = 0; i < mn.F.F; ++i) a.pb(mn.F.S);
            for (int i = 0; i < mn.S; ++i) a.pb(p.F);
        } else if (p.S < 0){
            p.S = -p.S;
            int t = 1, k = p.F;
            pair<pii, int> mn = {{0, 1}, p.S};
            while (k*p.F <= 1e7) {
                t++; k*=p.F;
                if (mn.F.F+mn.S > p.S/t+p.S%t) mn = {{p.S/t, k}, p.S%t};
            }
            for (int i = 0; i < mn.F.F; ++i) b.pb(mn.F.S);
            for (int i = 0; i < mn.S; ++i) b.pb(p.F);
        }
    }

    cout << max(1ll, sz(a)) << ' ' << max(1ll, sz(b)) << '\n';
    for (int &x : a) cout << x << ' ';
    if (sz(a) == 0) cout << 1;
    cout << '\n';
    for (int &x : b) cout << x << ' ';
    if (sz(b) == 0) cout << 1;

    return 0;
}