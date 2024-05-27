#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
#define int ll
const int INF = 1e9;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s; cin >> s;

    for (int i = 0; i < s.size(); ++i){
        int newI = (s[i] - '0');
        if (9 - newI < newI){
            if (i == 0 && 9 - newI == 0) continue;
            s[i] = '9' - newI;
        }
    }

    cout << s;

    return 0;
}