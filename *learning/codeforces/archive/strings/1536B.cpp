#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>

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

bool comp(string a, string b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int32_t main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    vector<string> vec;
    string empt = "";
    for (int i = 0; i < 26; ++i){
        vec.pb(empt + (char)('a' + i));
    }
    for (int i = 0; i < 26; ++i){
        for (int j = 0; j < 26; ++j){
            vec.pb(empt + (char)('a' + i) + (char)('a' + j));
        }
    }
    for (int i = 0; i < 26; ++i){
        for (int j = 0; j < 26; ++j){
            for (int k = 0; k < 26; ++k){
                vec.pb(empt + (char)('a' + i) + (char)('a' + j) + (char)('a' + k));
            }
        }
    }
    sort(all(vec), comp);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;

        unordered_map<string, int> mp1, mp2, mp3;
        for (int i = 0; i < n; ++i){
            mp1[empt + s[i]] = 1;
        }
        for (int i = 0; i < n-1; ++i){
            mp2[empt + s[i] + s[i+1]] = 1;
        }
        for (int i = 0; i < n-2; ++i){
            mp3[empt + s[i] + s[i+1] + s[i+2]] = 1;
        }

        for (string &guess : vec){
            if (!mp1[guess] && !mp2[guess] && !mp3[guess]) {
                cout << guess << '\n';
                break;
            }
        }
    }

    return 0;
}