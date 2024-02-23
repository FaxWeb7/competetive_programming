#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
private:
    vector<int> tree;
    int n;

    void buildTree(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(nums, 2 * node + 1, start, mid);
            buildTree(nums, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || left > end) {
            return 0;
        }
        if (left <= start && right >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, left, right) + query(2 * node + 2, mid + 1, end, left, right);
    }

    void update(int node, int start, int end, int index, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(2 * node + 1, start, mid, index, val);
            } else {
                update(2 * node + 2, mid + 1, end, index, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree(vector<int>& nums, int n) {
        this->n = n;
        tree.resize(4 * n, 0);
        buildTree(nums, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    void updateVal(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int n = 6;
    SegmentTree segTree(nums, n);

    cout << segTree.sumRange(0, 2) << endl;
    segTree.updateVal(0, 100);
    cout << segTree.sumRange(2, 5) << endl;

    return 0;
}
