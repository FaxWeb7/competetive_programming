#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end){
        if (start == end){
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2*node+1, start, mid);
            build(nums, 2*node+2, mid+1, end);
            tree[node] = max(tree[2*node+1], tree[2*node+2]);
        }
    }

    int getMax(int node, int start, int end, int left, int right){
        if (left > end || right < start){
            return 0;
        }
        if (left <= start && right >= end){
            return tree[node];
        }
        int mid = (start + end) / 2;
        return max(getMax(2*node+1, start, mid, left, right), getMax(2*node+2, mid+1, end, left, right));
    }

    void updateVal(int node, int start, int end, int index, int value){
        if (start == end){
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                updateVal(2*node+1, start, mid, index, value);
            } else {
                updateVal(2*node+2, mid+1, end, index, value);
            }
            tree[node] = max(tree[2*node+1], tree[2*node+2]);
        }
    }

public:
    SegmentTree(vector<int>& nums, int n){
        this->n = n;
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
    }

    int query(int left, int right){
        return getMax(0, 0, n-1, left, right);
    }

    void update(int index, int value){
        updateVal(0, 0, n-1, index, value);
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree tree(arr, n);
    cin >> k;
    for (int i = 0; i < k; i++){
        char command;
        cin >> command;
        if (command == 's'){
            int l, r;
            cin >> l >> r;
            cout << tree.query(l-1, r-1) << " ";
        } else {
            int idx, newVal;
            cin >> idx >> newVal;
            tree.update(idx-1, newVal);
        }
    }

    return 0;
}