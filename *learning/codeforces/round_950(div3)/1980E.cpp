#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m)), b(n, vi(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> b[i][j];
    }

    bool gOk = true;

    vector<vi> ac = a;
    vector<vi> bc = b;
    map<vi, int> mpa;
    for (vi &vec : ac){
        sort(all(vec));
        mpa[vec]++;
    }
    for (vi &vec : bc){
        sort(all(vec));
        if (mpa[vec] == 0) gOk = false;
    }

    mpa.clear();
    ac = a;
    bc = b;
    for (int i = 0; i < m; ++i){
        vi vec(n);
        for (int j = 0; j < n; ++j) vec[j] = ac[j][i];
        sort(all(vec));

        mpa[vec]++;
    }
    for (int i = 0; i < m; ++i){
        vi vec(n);
        for (int j = 0; j < n; ++j) vec[j] = bc[j][i];
        sort(all(vec));

        if (mpa[vec] == 0) gOk = false;
    }

    cout << (gOk ? "YES\n" : "NO\n");
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}