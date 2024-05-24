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
    int t;
    cin >> t;
    while (t--){
        int a, b, n, m;
        cin >> a >> b >> n >> m;

        // mpx[i] - кол-во шаров в строке i
        set<ii> st;
        for (int i = 0; i < n; ++i){
            int y, x;
            cin >> y >> x;
            st.insert({y, x});
        }

        int score1 = 0, score2 = 0;
        int cutUp = 1, cutLeft = 1;
        int curMove = 1;
        while (m--){
            char c;
            int k;
            cin >> c >> k;

            int cnt = 0;
            if (c == 'U'){
                for (int i = cutUp; i < cutUp+k && i <= a; ++i){
                    for (int j = 1; j <= b; ++j){
                        if (*st.lower_bound({i, j}) == ii{i, j}) {
                            cnt++;
                            st.erase({i, j});
                        }
                    }
                }
                cutUp += k;
            } else if (c == 'L'){
                for (int i = cutLeft; i < cutLeft+k && i <= b; ++i){
                    for (int j = 1; j <= a; ++j){
                        if (*st.lower_bound({j, i}) == ii{j, i}) {
                            cnt++;
                            st.erase({j, i});
                        }
                    }
                }
                cutLeft += k;
            } else if (c == 'D'){
                for (int i = a; i > a-k && i >= 1; --i){
                    for (int j = 1; j <= b; ++j){
                        if (*st.lower_bound({i, j}) == ii{i, j}) {
                            cnt++;
                            st.erase({i, j});
                        }
                    }
                }
                a -= k;
            } else if (c == 'R'){
                for (int i = b; i > b-k && i >= 1; --i){
                    for (int j = 1; j <= a; ++j){
                        if (*st.lower_bound({j, i}) == ii{j, i}) {
                            cnt++;
                            st.erase({j, i});
                        }
                    }
                }
                b -= k;
            }

            if (curMove == 1) score1 += cnt;
            else score2 += cnt;
            curMove = 3 - curMove;
        }

        cout << score1 << ' ' << score2 << '\n';
    }

    return 0;
}