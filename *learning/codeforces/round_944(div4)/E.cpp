#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
#define all(x) x.begin(), x.end()

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, k, q;
        cin >> n >> k >> q;
        vi a(k + 1), b(k + 1), queries(q);
        for (int i = 1; i <= k; ++i) cin >> a[i];
        for (int i = 1; i <= k; ++i) cin >> b[i];
        for (int i = 0; i < q; ++i) cin >> queries[i];

        for (int &d : queries){
            int leftIdx = upper_bound(all(a), d) - a.begin();
            leftIdx--;

            if (a[leftIdx] == d){
                cout << b[leftIdx] << ' ';
                continue;
            }

            double mod = (d - a[leftIdx]) * ((double)(b[leftIdx+1] - b[leftIdx]) / (a[leftIdx+1] - a[leftIdx]));
            cout << int(b[leftIdx] + mod) << ' ';
        }

        cout << '\n';
    }

    return 0;
}