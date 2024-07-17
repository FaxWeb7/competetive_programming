#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

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
    int n = s.size();

    stack<int> st;
    int mx = 0, cnt = 1;
    for (int i = 0; i < n; ++i){
        if (s[i] == ')' && st.size() && s[st.top()] == '(') st.pop();
        else st.push(i);

        int r = st.size() ? i-st.top() : i+1;
        if (r > mx) mx = r, cnt = 1;
        else if (r == mx && r) cnt++;
    }

    cout << mx << ' ' << cnt;

    return 0;
}