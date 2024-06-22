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
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const double PI = acos(-1);
const double EPS = 1e-10;
const int INF = 1e9 + 6;

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int s, e, n; cin >> s >> e >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int closePortal = abs(s - a[0]);
    int closePortal2 = abs(e - a[0]);
    for (int &portal : a){
        closePortal = min(closePortal, abs(s - portal));
        closePortal2 = min(closePortal2, abs(e - portal));
    }

    if (closePortal >= abs(s-e)) cout << abs(s-e);
    else cout << closePortal + 1 + closePortal2;

    return 0;
}
