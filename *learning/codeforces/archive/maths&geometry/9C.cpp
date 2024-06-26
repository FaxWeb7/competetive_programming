#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define F first
#define S second
const int INF = 1e9;

int solve(int n, string cur, int &res){
    if (cur.length() == to_string(n).length()){
        return res;
    }

    if (cur.length() != 0 && stoi(cur + '0') <= n) {
        res++;
        solve(n, cur + '0', res);
    }
    if (stoi(cur + '1') <= n) {
        res++;
        solve(n, cur + '1', res);
    }
    
    return res;
}

int main(){
    int n; cin >> n;
    
    int res = 0;
    string cur = "";
    cout << solve(n, cur, res);

    return 0;
}