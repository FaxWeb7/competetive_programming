#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct SegmentTree {
private:
    vector<ll> tree;
    int n;

    void build(vector<ll>& nums, int node, int start, int end){
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = (start + end) / 2;
            build(nums, 2*node+1, start, mid);
            build(nums, 2*node+2, mid+1, end);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    ll sumQuery(int node, int start, int end, int left, int right){
        if (left > end || right < start){
            return 0;
        }
        if (left <= start && right >= end){
            return tree[node];
        }
        int mid = (start + end) / 2;
        return sumQuery(2*node+1, start, mid, left, right) + sumQuery(2*node+2, mid+1, end, left, right);
    }

public:
    SegmentTree(vector<ll>& nums, int n){
        this->n = n;
        tree.resize(4*n);
        build(nums, 0, 0, n-1);
    }

    ll getSum(ll left, ll right){
        return sumQuery(0, 0, n-1, left, right);
    }
};

int main(){
    int n, k;
    ll l, r;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree tree(arr, n);
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> l >> r;
        cout << tree.getSum(l-1, r-1) << " ";
    }

    return 0;
}