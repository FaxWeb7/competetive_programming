#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int priority;
    int val;
    int size;
    Node* left;
    Node* right;

    Node(int val){
        priority = rand();
        this->val = val;
        size = 1;
        left = right = nullptr;
    }
};

struct ImplicitTreap{
private:
    Node* root = nullptr;

    int getSize(Node* root){
        return (root ? root->size : 0);
    }

    void updateSize(Node* root){
        if (!root) return;
        root->size = getSize(root->left) + 1 + getSize(root->right);
    }

    Node* mergeRec(Node* L, Node* R){
        if (L == nullptr) return R; 
        if (R == nullptr) return L; 

        if (L->priority > R->priority){
            L->right = mergeRec(L->right, R);
            updateSize(L);
            return L;
        } else{
            R->left = mergeRec(L, R->left);
            updateSize(R);
            return R;
        }
    }

    void splitRec(Node* root, int x, Node*& L, Node*& R){
        if (root == nullptr){
            L = R = nullptr;
        }
        else if (getSize(root->left) < x) {
            splitRec(root->right, x - getSize(root->left) - 1, root->right, R);
            L = root;
        } else {
            splitRec(root->left, x, L, root->left);
            R = root;
        }
        updateSize(L);
        updateSize(R);
    }

public:
    void pushBack(int val) {
        Node* newNode = new Node(val);
        root = mergeRec(root, newNode);
    }

    void toFront(int l, int r){
        Node *left, *mid, *right;
        splitRec(root, l, left, right);
        splitRec(right, r-l+1, mid, right);
        root = mergeRec(mergeRec(mid, left), right);
    }

    int get(int index){
        Node *left, *mid, *right;
        splitRec(root, index, left, right);
        splitRec(right, 1, mid, right);
        root = mergeRec(mergeRec(left, mid), right);
        return mid->val;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    ImplicitTreap treap;
    for (int i = 1; i <= n; i++) {
        treap.pushBack(i);
    }

    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        treap.toFront(l-1, r-1);
    }

    for (int i = 0; i < n; i++){
        cout << treap.get(i) << " ";
    }

    return 0;
}