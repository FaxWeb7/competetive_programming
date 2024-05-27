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
#define int ll
const int INF = 1e9;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int x; cin >> x;
        vector<int> res;
        while (x > 0) {
            if (x % 2 == 0) {
                res.push_back(0);
            } else {
                if (x % 4 == 1) {
                    res.push_back(1);
                    x -= 1;
                } else {
                    res.push_back(-1);
                    x += 1;
                }
            }
            x /= 2;
        }

        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int, int> ii;
// #define all(x) x.begin(), x.end()
// #define MP make_pair
// #define F first
// #define S second
// #define int ll
// const int INF = 1e9;

// void bin(string &res, int n){
//     if (n > 1)
//         bin(res, n / 2);

//     res += (n % 2) + '0';
// }

// int32_t main(){
//     ios::sync_with_stdio(false), cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--){
//         int x; cin >> x;
        
//         string binX = "";
//         bin(binX, x);
//         cout << "BIN: " << binX << '\n';

//         vi ans;
//         for (int i = 0; i < binX.size(); ++i){
//             if (i+1 < binX.size() && binX[i] == '1' && binX[i+1] == '1'){
//                 int r = i + 1;
//                 while (r+1 < binX.size() && binX[r+1] == '1') r++;

//                 ans.push_back(1);
//                 for (int j = 0; j < r-i; ++j) ans.push_back(0);
//                 ans.push_back(-1);
//                 i = r;
//             } else {
//                 ans.push_back((binX[i] == '1' ? 1 : 0));
//             }
//         }

//         reverse(all(ans));
//         cout << ans.size() << '\n';
//         for (int i : ans) cout << i << ' ';
//         cout << '\n';
//     }

//     return 0;
// }