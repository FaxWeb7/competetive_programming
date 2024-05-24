#include <iostream>
#include <vector>
#include <unordered_map>
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


int main(){
    int t;
    cin >> t;
    while (t--){
        unordered_map<char, int> dx{{'N', 1}, {'S', -1}, {'E', 0}, {'W', 0}};
        unordered_map<char, int> dy{{'N', 0}, {'S', 0}, {'E', 1}, {'W', -1}};
        int n; cin >> n;
        string s; cin >> s;

        int x = 0, y = 0;
        for (char &c : s){
            x += dx[c];
            y += dy[c];
        }

        if ((x % 2 || y % 2) || (!x && !y && n == 2)) {
            cout << "NO\n";
            continue;
        }

        x /= 2, y /= 2;
        cout << "R";
        x -= dx[s[0]], y -= dy[s[0]];

        for (int i = 1; i < n; ++i){
            if (abs(x - dx[s[i]]) < abs(x) || abs(y - dy[s[i]]) < abs(y)){
                cout << "R";
                x -= dx[s[i]], y -= dy[s[i]];
            } else cout << "H";
        }
        cout << '\n';
    }

    return 0;
}