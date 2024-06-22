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
    int n, k; cin >> n >> k;

    cout << (n/k - 1) * n * 2;

    return 0;
}
