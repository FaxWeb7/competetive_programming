#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>

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
    string start, finish; cin >> start >> finish;
    int sh = stoi(start.substr(0, 2)), sm = stoi(start.substr(3, 5));
    int fh = stoi(finish.substr(0, 2)), fm = stoi(finish.substr(3, 5));

    int mid = (((fh-sh) * 60) + (fm-sm)) / 2;

    int midH = sh + (mid / 60);
    mid %= 60;

    int midM = sm + mid;
    if (midM >= 60) {
        midH++;
        midM %= 60;
    }

    cout << setfill('0') << setw(2) << midH << ':';
    cout << setfill('0') << setw(2) << midM << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();

    return 0;
}