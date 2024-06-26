#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

void solve(){
    int x, y, k; cin >> x >> y >> k;

    while (k > 0 && x != 1){
        int d = y - (x % y);
        x += min(k, d), k -= min(k, d);
        while (x % y == 0) x /= y;
    }

    cout << x + (k % (y - (x % y))) << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <vector>

// using namespace std;
// typedef long long ll;
// #define int ll
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef pair<int, int> pii;
// #define all(x) x.begin(), x.end()
// #define pb push_back
// #define MP make_pair
// #define F first
// #define S second
// const double EPS = 1e-10;
// const int INF = 1e9 + 7;

// void solve(){
//     int x, y, k; cin >> x >> y >> k;

//     while (k > 0 && x != 1){
//         int d = (x / y + 1) * y - x;
//         d = max(1ll, d);
//         d = min(k, d);
//         x += d, k -= d;
//         while (x % y == 0) x++;
//     }

//     cout << x + k % (y - 1) << '\n';
// }

// int32_t main(){
//     ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--){
//         solve();
//     }

//     return 0;
// }