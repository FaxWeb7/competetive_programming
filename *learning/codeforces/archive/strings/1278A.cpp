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
    string p, h; cin >> p >> h;
    map<char, int> mpp, mph;
    for (char &c : p) mpp[c]++;
    for (char &c : h) mph[c]++;

    bool match = true;
    for (auto &[c, cnt] : mpp){
        if (mph[c] < cnt) match = false;
    }

    bool exist = false;
    for (int i = 0; i < h.size(); ++i){
        if (mpp[h[i]]){
            map<char, int> mppCopy = mpp;
            int j = i;
            mppCopy[h[j]]--;
            while (j+1 < h.size() && mppCopy[h[j+1]] > 0) mppCopy[h[++j]]--;
            
            bool ok = true;
            for (auto &item : mppCopy){
                if (item.S != 0) ok = false;
            }
            if (ok) exist = true;
        }
    }

    cout << (match && exist ? "YES\n" : "NO\n");
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