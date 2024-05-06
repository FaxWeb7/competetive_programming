#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& tree, int n, int index, int delta) {
    while (index < n) {
        tree[index] += delta;
        index += index & -index;
    }
}

int query(const vector<int>& tree, int index) {
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & -index;
    }
    return sum;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int n = nums.size();
    vector<int> fenwick(n + 1, 0);

    for (int i = 0; i < n; i++) {
        update(fenwick, n, i + 1, nums[i]);
    }

    update(fenwick, n, 2, 6);
    cout << "Сумма элементов на отрезке [1, 3]: " << query(fenwick, 3) << endl;
    cout << "Сумма элементов на отрезке [2, 5]: " << query(fenwick, 5) - query(fenwick, 1) << endl;

    return 0;
}
