#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    int index;
    Node(int value, int index) : value(value), index(index) {};
};

struct SegmentTree {
private:
    vector<Node> tree;
    int n;

    void build(vector<int>& nums, int node, int start, int end){
        if (start == end) {
            tree[node] = {nums[start], start+1};
        } else {
            int mid = (start + end) / 2;
            build(nums, 2*node+1, start, mid);
            build(nums, 2*node+2, mid+1, end);
            tree[node].value = max(tree[2*node+1].value, tree[2*node+2].value);
            if (tree[node].value == tree[2*node+1].value){
                tree[node].index = tree[2*node+1].index;
            } else {
                tree[node].index = tree[2*node+2].index;
            }
        }
    }

    Node maxQueryIndex(int node, int start, int end, int left, int right){
        if (left > end || right < start){
            return {0,0};
        }
        if (left <= start && right >= end){
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node maxL = maxQueryIndex(2*node+1, start, mid, left, right);
        Node maxR = maxQueryIndex(2*node+2, mid+1, end, left, right);
        if (maxL.value >= maxR.value) return maxL;
        return maxR;
    }

public:
    SegmentTree(vector<int>& nums, int n){
        this->n = n;
        tree.resize(4*n, {0,0});
        build(nums, 0, 0, n-1);
    }

    int getMaxIndex(int left, int right){
        return maxQueryIndex(0, 0, n-1, left, right).index;
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
        cout << tree.getMaxIndex(l-1, r-1) << " ";
    }

    return 0;
}