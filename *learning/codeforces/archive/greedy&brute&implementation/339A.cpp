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

    vector<char> a;
    for (char &c : s){
        if (c != '+') a.push_back(c);
    }

    int cnt = 0;
    sort(all(a));
    for (char &c : a){
        if (cnt == 0){
            cnt = 1;
            cout << c;
        } else {
            cout << '+' << c;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}