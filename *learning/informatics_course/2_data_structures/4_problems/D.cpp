#include <iostream>
#include <random>
#include <algorithm>
using namespace std;
using ll = long long;

mt19937 randNum(123);

struct Node{
    ll priority, val, minVal;
    int size;
    Node* left;
    Node* right;

    Node(ll val) : priority(randNum()), val(val), minVal(val), size(1), left(nullptr), right(nullptr){};
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

    Node* mergeRec(Node* L, Node* R){
        if (!L) return R;
        if (!R) return L;

        if (L->priority > R->priority){
            L->right = mergeRec(L->right, R);
            update(L);
            return L;
        } else{
            R->left = mergeRec(L, R->left);
            update(R);
            return R;
        }
    }

    void splitRec(Node* root, int x, Node*& L, Node*& R){
        if (!root) L = R = nullptr;
        else if (getSize(root->left) < x){
            splitRec(root->right, x - getSize(root->left) - 1, root->right, R);
            L = root;
        } else{
            splitRec(root->left, x, L, root->left);
            R = root;
        }
        update(L);
        update(R);
    }

public:
    void insertByIndex(int index, ll val){
        Node *left, *right;
        splitRec(root, index, left, right);
        Node* newNode = new Node(val);
        root = mergeRec(mergeRec(left, newNode), right);
    }

    ll getMinBetween(int i, int j){
        Node *left, *mid, *right;
        splitRec(root, i, left, right);
        splitRec(right, j-i+1, mid, right);
        ll res = getMinVal(mid);
        root = mergeRec(mergeRec(left, mid), right);
        return res;
    }
};

int main(){
    int n;
    cin >> n;

    ImplicitTreap treap;
    for (int i = 0; i < n; i++){
        char command;
        cin >> command;
        if (command == '+'){
            int i;
            ll x;
            cin >> i >> x;
            treap.insertByIndex(i, x);
        } else {
            int i, j;
            cin >> i >> j;
            cout << treap.getMinBetween(i-1, j-1) << endl;
        }
    }

    return 0;
}
