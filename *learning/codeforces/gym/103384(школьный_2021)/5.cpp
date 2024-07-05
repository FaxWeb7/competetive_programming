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

int ceil_div(int a, int b){
    return (a + b - 1) / b;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x, y; cin >> x >> y;

    if (x == y) cout << (x == 1 ? 1 : -1);
    else {
        int k = ceil_div(x-1, y-x);
        cout << max(1ll, k*x);
    }

    return 0;
}
