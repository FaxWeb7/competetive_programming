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
    int x, y, n; cin >> x >> y >> n;

    int res = (n / (y + x)) * 2;
    n -= (n / (y + x)) * (y + x);

    int a = 1;
    while (n > 0){
        if (a) n -= y;
        else n -= x;
        a = 1 - a;
        res++;
    }

    cout << res;

    return 0;
}
