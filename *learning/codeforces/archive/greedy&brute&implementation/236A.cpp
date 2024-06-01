#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

void solve(){
    string s; cin >> s;
    set<char> st;
    for (int i = 0; i < s.size(); ++i){
        st.insert(s[i]);
    }

    cout << (st.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}