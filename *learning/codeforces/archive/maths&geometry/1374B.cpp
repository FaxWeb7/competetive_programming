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

void solve(){
    int n; cin >> n;

    vi a{1, 6, 36, 216, 1296, 7776, 46656, 279936, 1679616, 10077696, 60466176, 362797056, 2176782336, 13060694016, 78364164096, 470184984576, 2821109907456, 16926659444736, 101559956668416, 609359740010496, 3656158440062976, 21936950640377856, 131621703842267136, 789730223053602816, 4738381338321616896};

    int res = 0;
    while (find(all(a), n) == a.end()){
        n *= 2, res++;
        if (n >= 1e18) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << res + (find(all(a), n)-a.begin()) << '\n';
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