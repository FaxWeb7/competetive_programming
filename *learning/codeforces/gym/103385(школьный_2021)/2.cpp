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

void solve(){
    int n1, n2; cin >> n1 >> n2;
    
    if (n2 % 2 == 0){
        if (n1 % 2 == 1) cout << "No";
        else cout << "Yes\n" << n1/2 << ' ' << n2/2;
    } else if (n2 % 2 == 1) {
        if (n1 % 2 == 0 && n1 >= 2) cout << "Yes\n" << 2 + (n1-2)/2 << ' ' << n2/2;
        else cout << "No";
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}