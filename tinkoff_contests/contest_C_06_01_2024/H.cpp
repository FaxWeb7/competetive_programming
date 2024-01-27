#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> planet(n);
    for (int i = 0; i < n; i++) {
        cin >> planet[i];
    }

    int max_k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (planet[i][j] == '#') {
                int k = 1;
                while (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m) {
                    if (planet[i - k][j] == '#' && planet[i + k][j] == '#' && planet[i][j - k] == '#' && planet[i][j + k] == '#') {
                        max_k = max(max_k, k);
                        k++;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    cout << max_k << endl;

    return 0;
}
