#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < q; i++) {
        int ki;
        cin >> ki;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (A[j] - count <= ki-1) {
                count++;
            } else {
                break;
            }
        }

        cout << ki-1 + count << " ";
    }

    return 0;
}