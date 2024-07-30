#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
// #define int ll
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
const int INF = 2e9 + 1;
const int MOD = 1e9 + 7;

pii check(int y, int x, int ty, int tx){
    int i = 0;
    while (ty-i >= 1 && tx-i >= 1){
        if (ty-i == y && tx-i == x) return {y, x};
        i++;
    }
    i = 0;
    while (ty-i >= 1 && tx+i <= 8){
        if (ty-i == y && tx+i == x) return {y, x};
        i++;
    }
    i = 0;
    while (ty+i <= 8 && tx-i >= 1){
        if (ty+i == y && tx-i == x) return {y, x};
        i++;
    }
    i = 0;
    while (ty+i <= 8 && tx+i <= 8){
        if (ty+i == y && tx+i == x) return {y, x};
        i++;
    }

    return {-1, -1};
}

void solve(){
    int y, x, ty, tx; cin >> y >> x >> ty >> tx;

    if ((y % 2 == ty % 2 && x % 2 != tx % 2) || (y % 2 != ty % 2 && x % 2 == tx % 2)) {
        cout << "No";
        return;
    }

    cout << "Yes\n" << 2 << '\n';
    int i = 0;
    while (y-i >= 1 && x-i >= 1){
        if (check(y-i, x-i, ty, tx).F != -1){
            cout << check(y-i, x-i, ty, tx).F << ' ' << check(y-i, x-i, ty, tx).S << '\n';
            cout << ty << ' ' << tx;
            return;
        }
        i++;
    }
    i = 0;
    while (y-i >= 1 && x+i <= 8){
        if (check(y-i, x+i, ty, tx).F != -1){
            cout << check(y-i, x+i, ty, tx).F << ' ' << check(y-i, x+i, ty, tx).S << '\n';
            cout << ty << ' ' << tx;
            return;
        }
        i++;
    }
    i = 0;
    while (y+i <= 8 && x-i >= 1){
        if (check(y+i, x-i, ty, tx).F != -1){
            cout << check(y+i, x-i, ty, tx).F << ' ' << check(y+i, x-i, ty, tx).S << '\n';
            cout << ty << ' ' << tx;
            return;
        }
        i++;
    }
    i = 0;
    while (y+i <= 8 && x+i <= 8){
        if (check(y+i, x+i, ty, tx).F != -1){
            cout << check(y+i, x+i, ty, tx).F << ' ' << check(y+i, x+i, ty, tx).S << '\n';
            cout << ty << ' ' << tx;
            return;
        }
        i++;
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}