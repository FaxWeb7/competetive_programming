#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end){
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2*node+1, start, mid);
            build(nums, 2*node+2, mid+1, end);
            tree[node] = max(tree[2*node+1], tree[2*node+2]);
        }
    }

    int maxQuery(int node, int start, int end, int left, int right){
        if (left > end || right < start){
            return 0;
        }
        if (left <= start && right >= end){
            return tree[node];
        }
        int mid = (start + end) / 2;
        return max(maxQuery(2*node+1, start, mid, left, right), maxQuery(2*node+2, mid+1, end, left, right));
    }

public:
    SegmentTree(vector<int>& nums, int n){
        this->n = n;
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
    }

    int getMax(int left, int right){
        return maxQuery(0, 0, n-1, left, right);
    }
};

int main(){
    int n, k;
    int l, r;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree tree(arr, n);
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> l >> r;
        cout << tree.getMax(l-1, r-1) << " ";
    }

    return 0;
}