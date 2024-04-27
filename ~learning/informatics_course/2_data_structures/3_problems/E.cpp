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

    Node* insertRec(Node* root, int val){
        if (root == nullptr) return new Node(val);

        if (val < root->key){
            root->left = insertRec(root->left, val);
        }
        if (val > root->key){
            root->right = insertRec(root->right, val);
        }
        return root;
    }

    void printLeafsRec(Node* root){
        if (root == nullptr) return;
        
        printLeafsRec(root->left);
        if (root->right == nullptr && root->left == nullptr){
            cout << root->key << endl;
        }
        printLeafsRec(root->right);
    }

public:
    void insert(int val){
        root = insertRec(root, val);
    }
    void printLeafs(){
        printLeafsRec(root);
    }
};

int main(){
    BST tree;
    int num;
    while (true){
        cin >> num;
        if (num == 0) break;
        tree.insert(num);
    }

    tree.printLeafs();

    return 0;
}