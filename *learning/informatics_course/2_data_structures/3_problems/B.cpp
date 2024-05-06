#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int val){
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

struct BST{
private:
    Node* root = nullptr;
    int treeLen = 0;

    Node* insertRec(Node* root, int val){
        if (root == nullptr) return new Node(val);

        else if (val < root->key){
            root->left = insertRec(root->left, val);
        }
        else if (val > root->key){
            root->right = insertRec(root->right, val);
        }
        return root;
    }

    void getTreeLenRec(Node* root){
        if (root == nullptr){
            return;
        }
        getTreeLenRec(root->left);
        getTreeLenRec(root->right);
        treeLen++;
    }

public:
    void insert(int val){
        root = insertRec(root, val);
    }
    int getTreeLen(){
        getTreeLenRec(root);
        return this->treeLen;
    }
};

int main(){
    BST tree;
    int num;
    while(true){
        cin >> num;
        if (num == 0) break;
        tree.insert(num);
    }

    cout << tree.getTreeLen();

    return 0;
}