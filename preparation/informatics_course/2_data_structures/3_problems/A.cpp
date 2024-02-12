#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key = key;
        left = nullptr;
        right = nullptr;
    }
};

struct BST{
private:
    Node* root = nullptr;

    Node* insertRec(Node* root, int val){
        if (root == nullptr) {
            root = new Node(val);
        }
        if (val < root->key){
            root->left = insertRec(root->left, val);
        }
        if (val > root->key){
            root->right = insertRec(root->right, val);
        }
        return root;
    }

    int maxDepth(Node* root){
        if (root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth)+1;
    }

public:
    void insert(int val){
        root = insertRec(root, val);
    }
    int getMaxHeight(){
        return maxDepth(root);
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

    cout << tree.getMaxHeight();

    return 0;
}