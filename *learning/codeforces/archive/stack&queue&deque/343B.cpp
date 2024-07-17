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

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s; cin >> s;

    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i){
        if (i % 2) {
            if (s[i] == '+') a++;
            else b++;
        } else {
            if (s[i] == '+') b++;
            else a++;
        }
    }

    cout << (a == b ? "Yes\n" : "No\n");

    return 0;
}
