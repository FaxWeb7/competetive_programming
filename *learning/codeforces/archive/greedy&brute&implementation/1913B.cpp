#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
// #define int ll
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
    string s; cin >> s;
    map<char, int> mp;
    for (char &ch : s) mp[ch]++;

    int cnt = 0;
    for (char &ch : s){
        if (ch == '1' && mp['0']){
            cnt++;
            mp['0']--;
        } else if (ch == '0' && mp['1']){
            cnt++;
            mp['1']--;
        } else break;
    }
    
    cout << s.size()-cnt << '\n';
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