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
#define pb push_back
#define MP make_pair
#define F first
#define S second
const double EPS = 1e-10;
const int INF = 1e9 + 7;

vi pref(300001);

void solve(){
    int a, b; cin >> a >> b;


    int x = pref[a-1];

    if (x == b) cout << a << '\n';
    else if (a != (b ^ x)) cout << a+1 << '\n';
    else if (a == (b ^ x)) cout << a+2 << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    pref[0] = 0;
    for (int i = 1; i < 300002; ++i) pref[i] = pref[i-1] ^ i;

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}