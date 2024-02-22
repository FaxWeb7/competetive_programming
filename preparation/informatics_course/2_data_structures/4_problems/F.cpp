#include <iostream>
#include <vector>
#include <random>
using namespace std;

mt19937 randNum(123);

struct Node{
    int priority = randNum(), size = 1;
    int val, sum;
    Node *left = nullptr, *right = nullptr;
    Node(int val) : val(val), sum(val) {};
};

struct ImplicitTreap{
private:
    Node* root = nullptr;

    int getSize(Node* root){
        return root ? root->size : 0;
    }

    int getSum(Node* root){
        return root ? root->sum : 0;
    }

    void update(Node* root){
        if (!root) return;
        root->size = getSize(root->left) + 1 + getSize(root->right);
        root->sum = getSum(root->left) + root->val + getSum(root->right);
    }

    Node* merge(Node* L, Node* R){
        if (!L) return R;
        if (!R) return L;

        if (L->priority > R->priority){
            L->right = merge(L->right, R);
            update(L);
            return L;
        } else {
            R->left = merge(L, R->left);
            update(R);
            return R;
        }
    }

    void split(Node* root, int x, Node*& L, Node*& R){
        if (!root) L = R = nullptr;
        else if (getSize(root->left) < x){
            split(root->right, x - getSize(root->left) - 1, root->right, R);
            L = root;
        } else {
            split(root->left, x, L, root->left);
            R = root;
        }
        update(L);
        update(R);
    }

public:
    void pushBack(int val){
        root = merge(root, new Node(val));
    }

    void shift(int l, int r){
        Node *left, *mid, *right;
        split(root, l, left, right);
        split(right, r-l+1, mid, right);

        Node *newMid = nullptr;
        while (mid){
            Node *tempL, *tempM, *tempR;
            split(mid, 2, tempL, tempR);
            split(tempL, 1, tempM, tempL);
            newMid = merge(newMid, merge(tempL, tempM));
            mid = tempR;
        }

        root = merge(merge(left, newMid), right);
    }

    int getSumSegment(int l, int r){
        Node *left, *mid, *right;
        split(root, l, left, right);
        split(right, r-l+1, mid, right);
        int res = getSum(mid);
        root = merge(merge(left, mid), right);
        return res;
    }
};

int main(){
    vector<vector<int>> res;
    int cnt = 0;

    int n, m, type, l, r;
    while (true){
        ImplicitTreap treap;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++){
            int val;
            cin >> val;
            treap.pushBack(val);
        }
        
        res.push_back({});
        for (int i = 0; i < m; i++){
            cin >> type >> l >> r;
            if (type == 1){
                treap.shift(l-1, r-1);
            } else {
                res[cnt].push_back(treap.getSumSegment(l-1, r-1));
            }
        }
        cnt++;
    }

    for (int i = 0; i < res.size(); i++){
        cout << "Swapper " << i+1 << ":\n";
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}