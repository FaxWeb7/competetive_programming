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

bool check(int n){
    if (n < 4) return false;
    if (n == 4 || n == 7) return true;
    return (check(n-4) || check(n-7));
}

void solve(){
    int n; cin >> n;

    string res = "";
    while(n > 0) {
        if(n % 7 == 0){
            res += '7';
            n -= 7;
    }
        else {
            res += '4';
            n -= 4;
        }
    }
    if (!n) cout << res;
    else cout<< -1 ;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}