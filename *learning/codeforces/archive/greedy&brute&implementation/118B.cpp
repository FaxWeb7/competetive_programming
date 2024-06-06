#include <iostream>
#include <algorithm>
#include <vector>

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
    int n; cin >> n;

    for (int i = 1; i <= (2*n+1)/2; ++i){
        string line = "";
        for (int j = 0; j < 2*(n-i+1); ++j) line += ' ';

        if (i == 1) line += "0 ";
        else {
            for (int j = 0; j < i-1; ++j) line += to_string(j) + ' ';
            line += to_string(i-1) + ' ';
            for (int j = i-2; j >= 0; --j) line += to_string(j) + ' ';
        }

        line = line.substr(0, line.size()-1);
        cout << line << '\n';
    }

    string mainLine = "";
    for (int j = 0; j < n; ++j) mainLine += to_string(j) + ' ';
    mainLine += to_string(n) + ' ';
    for (int j = n-1; j >= 0; --j) mainLine += to_string(j) + ' ';
    mainLine = mainLine.substr(0, mainLine.size()-1);
    cout << mainLine << '\n';

    for (int i = (2*n+1)/2; i >= 1; --i){
        string line = "";
        for (int j = 0; j < 2*(n-i+1); ++j) line += ' ';

        if (i == 1) line += "0 ";
        else {
            for (int j = 0; j < i-1; ++j) line += to_string(j) + ' ';
            line += to_string(i-1) + ' ';
            for (int j = i-2; j >= 0; --j) line += to_string(j) + ' ';
        }

        line = line.substr(0, line.size()-1);
        cout << line << '\n';
    }
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();

    return 0;
}