#include <iostream>
#include <random>
using namespace std;

mt19937 randNum(123);

struct Node {
    int priority;
    int val;
    int size = 1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val){
        priority = randNum();
        this->val = val;
    }
};

struct ImplicitTreap{
private:
    Node* root = nullptr;

    int getSize(Node* root){
        return (root ? root->size : 0);
    }

    void update(Node* root){
        if (!root) return;
        root->size = getSize(root->left) + 1 + getSize(root->right);
    }

    Node* merge(Node* L, Node* R){
        if (L == nullptr) return R; 
        if (R == nullptr) return L; 

        if (L->priority > R->priority){
            L->right = merge(L->right, R);
            update(L);
            return L;
        } else{
            R->left = merge(L, R->left);
            update(R);
            return R;
        }
    }

    void split(Node* root, int x, Node*& L, Node*& R){
        if (root == nullptr){
            L = R = nullptr;
        }
        else if (getSize(root->left) < x) {
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
    void pushBack(int val) {
        Node* newNode = new Node(val);
        root = merge(root, newNode);
    }

    int getByIndex(int index){
        Node *left, *mid, *right;
        split(root, index, left, right);
        split(right, 1, mid, right);
        root = merge(merge(left, mid), right);
        return mid->val;
    }
};

int main(){ 
    ImplicitTreap treap;
    treap.pushBack(1);
    treap.pushBack(2);
    treap.pushBack(3);
    treap.pushBack(4);
    treap.pushBack(5);

    cout << treap.getByIndex(0) << endl;

    return 0;
}