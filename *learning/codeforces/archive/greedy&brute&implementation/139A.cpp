#include <iostream>
#include <algorithm>
#include <vector>

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
    int n; cin >> n;
    vi a(7);
    int sum = 0;
    for (int i = 0; i < 7; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    n %= sum;
    n += sum;
    for (int i = 0; i < 14; ++i) {
        n -= a[i%7];
        if (n <= 0) {
            cout << (i%7)+1 << '\n';
            break;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}