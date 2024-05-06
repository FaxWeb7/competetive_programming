#include <iostream>
#include <random>
using namespace std;
using ll = long long;

mt19937 randNum(123);

struct Node{
    int priority = randNum(), size = 1, reverse = 0;
    ll val, minVal;
    Node *left = nullptr, *right = nullptr;
    Node(ll val) : val(val), minVal(val){};
};

struct ImplicitTreap{
private:
    Node* root = nullptr;

    int getSize(Node* root){
        return root ? root->size : 0;
    }

    ll getMinVal(Node* root){
        return root ? root->minVal : 2E9;
    }

    void update(Node* root){
        if (!root) return;
        root->size = getSize(root->left) + 1 + getSize(root->right);
        root->minVal = min(min(getMinVal(root->left), root->val), getMinVal(root->right));
    }

    void pushData(Node* root){
        if (!root) return;
        if (root->reverse){
            swap(root->left, root->right);
            if (root->left){
                root->left->reverse ^= 1;
            }
            if (root->right){
                root->right->reverse ^= 1;
            }
            root->reverse = 0;
        }
    }

    Node* merge(Node* L, Node* R){
        pushData(L);
        pushData(R);
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
        pushData(root);
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
    void pushBack(ll val){
        root = merge(root, new Node(val));
    }
    void reverse(int l, int r){
        Node *left, *mid, *right;
        split(root, l, left, right);
        split(right, r-l+1, mid, right);
        mid->reverse ^= 1;
        root = merge(merge(left, mid), right);
    }
    ll minimum(int l, int r){
        Node *left, *mid, *right;
        split(root, l, left, right);
        split(right, r-l+1, mid, right);
        ll res = getMinVal(mid);
        root = merge(merge(left, mid), right);
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    ImplicitTreap treap;
    for (int i = 0; i < n; i++){
        ll num;
        cin >> num;
        treap.pushBack(num);
    }

    for (int i = 0; i < m; i++){
        int command, left, right;
        cin >> command >> left >> right;
        if (command == 1){
            treap.reverse(left-1, right-1);
        } else {
            cout << treap.minimum(left-1, right-1) << endl;
        }
    }


    return 0;
}
