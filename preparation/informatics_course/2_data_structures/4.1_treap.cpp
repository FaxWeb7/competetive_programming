#include <iostream>
#include <random>
using namespace std;

mt19937 randomNum(123);

struct Node{
    int key;
    int priority;
    Node* left;
    Node* right;

    Node(int val) : key(val), priority(randomNum()), left(nullptr), right(nullptr) {}
};

struct Treap {
private:
    Node* root = nullptr;

    Node* mergeRec(Node* L, Node* R){
        if (L == nullptr) return R;
        if (R == nullptr) return L;

        if (L->priority > R->priority){
            L->right = mergeRec(L->right, R);
            return L;
        } 
        else {
            R->left = mergeRec(L, R->left);
            return R;
        }
    }

    void splitRec(Node* root, int x, Node*& L, Node*& R){
        if (root == nullptr){
            L = R = nullptr;
        }
        else if (root->key <= x){
            splitRec(root->right, x, root->right, R);
            L = root;
        }
        else {
            splitRec(root->left, x, L, root->left);
            R = root;
        }
    }


public:
    void insert(int val) {
        Node *left, *right;
        splitRec(root, val, left, right);
        Node* newNode = new Node(val);
        root = mergeRec(mergeRec(left, newNode), right);
    }

    void remove(int val){
        Node *left, *equal, *right;
        splitRec(root, val-1, left, right);
        splitRec(right, val, equal, right);
        root = mergeRec(left, right);
    }
};