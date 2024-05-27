// #include <iostream>
// #include <vector>
// #include <set>
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


// int32_t main(){
//     ios::sync_with_stdio(false), cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--){
//         int n, m; cin >> n >> m;
//         string x, s; cin >> x >> s;

//         int res = 0;
//         while (x.size() < s.size()){
//             x += x;
//             res++;
//         }

//         int r = 1;
//         while (x.find(s) == -1 && r <= x.size()){
//             rotate(x.begin(), x.begin()+r++, x.end());
//             res++;
//         }

//         cout << (x.find(s) != -1 ? res : -1) << '\n';
//     }

//     return 0;
// }

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
const int INF = 6;


int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        string x, s; cin >> x >> s;

        int cnt = 0;
        while (x.find(s) == -1 && cnt < INF){
            x += x;
            cnt++;
        }

        cout << (cnt != INF ? cnt : -1) << '\n';
    }

    return 0;
}