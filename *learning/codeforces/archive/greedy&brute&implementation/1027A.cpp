#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
// #define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9 + 6;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < n/2; ++i){
        if ((char)(s[i]-1) != (char)(s[n-i-1]-1) && (char)(s[i]-1) != (char)(s[n-i-1]+1) &&
            (char)(s[i]+1) != (char)(s[n-i-1]-1) && (char)(s[i]+1) != (char)(s[n-i-1]+1)){
                cout << "NO\n";
                return;
            }
    }

    cout << "YES\n";
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