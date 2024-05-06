#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;

        int k = 0;
        for (int i = 0, j = 0; i < n && j < m; ++j) {
            if (a[i] == b[j]) {
                ++k;
                ++i;
            }
        }

        cout << k << endl;
    }

    return 0;
}