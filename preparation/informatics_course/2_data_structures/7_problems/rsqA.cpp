#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Node {
    ll maxVal;
    int maxIndex;
    Node(ll maxVal, int maxIndex) : maxVal(maxVal), maxIndex(maxIndex) {};
};

struct RMQ {
private:
    vector<Node> tree;
    int n;

    void build(vector<ll>& nums, int node, int start, int end){
        if (start == end){
            tree[node] = {nums[start], start};
        } else {
            int mid = (start + end) / 2;
            build(nums, 2*node+1, start, mid);
            build(nums, 2*node+2, mid+1, end);
            tree[node].maxVal = max(tree[2*node+1].maxVal, tree[2*node+2].maxVal);
            if (tree[node].maxVal == tree[2*node+1].maxVal) {
                tree[node].maxIndex = tree[2*node+1].maxIndex;
            } else { 
                tree[node].maxIndex = tree[2*node+2].maxIndex;
            }
        }
    }

    Node query(int node, int start, int end, int left, int right){
        if (left > end || right < start){
            return {(ll)-1E9, 0};
        }
        if (left <= start && right >= end){
            return tree[node];
        }
        int mid = (start + end) / 2;
        Node lQuery = query(2*node+1, start, mid, left, right);
        Node rQuery = query(2*node+2, mid+1, end, left, right);
        return lQuery.maxVal > rQuery.maxVal ? lQuery : rQuery;
    }

public:
    RMQ(vector<ll>& nums, int n){
        this->n = n;
        tree.resize(4*n, {(ll)-1E9, 0});
        build(nums, 0, 0, n-1);
    }

    Node rangeMaxQuery(int l, int r){
        return query(0, 0, n-1, l, r);
    }
};

int main(){
    int n, k;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    RMQ tree(arr, n);
    cin >> k;
    for (int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        Node data = tree.rangeMaxQuery(l-1, r-1);
        cout << data.maxVal << " " << data.maxIndex+1 << endl;
    }

    return 0;
}