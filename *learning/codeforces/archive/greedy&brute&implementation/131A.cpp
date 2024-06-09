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
    string s; cin >> s;
    bool ok = false;

    for (int i = 1; i < s.size(); ++i){
        if (s[i] != toupper(s[i])) ok = true;
    }
    

    if (!ok) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == tolower(s[i])) s[i] = toupper(s[i]);
            else if (s[i] == toupper(s[i])) s[i] = tolower(s[i]);
        }
    }
    cout << s;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}