#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) {
        key = val;
        left = nullptr;
        right = nullptr;
    }
};

struct BST {
private:
    Node* root = nullptr;
    
    Node* insertRec(Node* root, int val) {
        if (root == nullptr) {
            root = new Node(val);
        }

        if (val < root->key) {
            root->left = insertRec(root->left, val);
        } 
        else if (val > root->key) {
            root->right = insertRec(root->right, val);
        }

        return root;
    }

    Node* searchRec(Node* root, int val) {
        if (root == nullptr || root->key == val) {
            return root;
        }
        else if (val < root->key){ 
            return searchRec(root->left, val);
        }
        else {
            return searchRec(root->right, val);
        }
    }

    int leftMaxNode(Node* root){
        while (root->right != NULL){
            root = root->right;
        }
        return root->key;
    }

    Node* removeRec(Node* root, int val){
        if (root == nullptr) return nullptr;

        if (root->key == val){
            if (root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            root->key = leftMaxNode(root->left);
            root->left = removeRec(root->left, root->key);
            return root;
        }

        if (val < root->key) root->left = removeRec(root->left, val); 
        if (val > root->key) root->right = removeRec(root->right, val);
        return root;
    }

    void printTreeRec(Node* root){
        if (root != nullptr){
            printTreeRec(root->left);
            cout << root->key << " ";
            printTreeRec(root->right);
        }
    }

public:
    void insert(int val) {
        root = insertRec(root, val);
    }

    bool search(int val) {
        if (searchRec(root, val) == nullptr){
            return false;
        } else return true;
    }

    void remove(int val){
        root = removeRec(root, val);
    }

    void printTree(){
        printTreeRec(root);
        cout << endl;
    }
};



int main(){
    BST tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(10);
    tree.insert(11);
    tree.remove(4);
    tree.printTree();
    cout << tree.search(5);

    return 0;
}