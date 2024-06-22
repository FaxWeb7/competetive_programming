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
    int n, k; cin >> n >> k;
    int maxK = 2 * ((((n-1) + (n % 2 ? 2 : 1))*(n/2))/2);
    if (k % 2 || k > maxK){
        cout << "No\n";
        return;
    }

    vi a(n);
    for (int i = 0; i < n; ++i) a[i] = i+1;

    int lastIdx = n-1;
    while (k > 0) {
        if (lastIdx-(k/2) >= n-lastIdx-1) {
            swap(a[lastIdx], a[lastIdx-(k/2)]);
            break;
        }
        else {
            swap(a[lastIdx], a[n-lastIdx-1]);
            k -= (abs((lastIdx+1) - a[lastIdx]) * 2);
            lastIdx--;
        }
    }


    cout << "Yes\n";
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
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