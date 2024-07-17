#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;
//#define int ll
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

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin >> n;

    deque<string> dq;
    while (n--){
        string op; cin >> op;
        if (op == "pwd") {
            cout << '/';
            for (auto it = dq.begin(); it != dq.end(); ++it){
                cout << *it << '/';
            }
            cout << '\n';
        }
        else {
            string newPath; cin >> newPath;
            if (newPath[0] == '/') dq.clear();
            for (int i = 0; i < newPath.size(); ++i){
                if (newPath[i] == '/') continue;
                if (newPath[i] == '.') {
                    dq.pop_back();
                    i += 2;
                } else {
                    string s = "";
                    while (i < newPath.size() && newPath[i] != '/'){
                        s += newPath[i++];
                    }
                    dq.push_back(s);
                }
            }
        }
    }

    return 0;
}