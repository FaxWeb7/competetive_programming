#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    int repeats;
    Node* left;
    Node* right;

    Node(int val){
        key = val;
        repeats = 1;
        left = nullptr;
        right = nullptr;
    }
};

struct BST{
private:
    Node* root = nullptr;

    Node* insertRec(Node* root, int val){
        if (root == nullptr) return new Node(val);

        if (val == root->key) root->repeats++;
        else if (val < root->key) {
            root->left = insertRec(root->left, val);
        }
        else if (val > root->key) {
            root->right = insertRec(root->right, val);
        }
        return root;
    }

    void printTreeRec(Node* root){
        if (root == nullptr) return;

        printTreeRec(root->left);
        cout << root->key << " " << root->repeats << endl;
        printTreeRec(root->right);
    }

public:
    void insert(int val){
        root = insertRec(root, val);
    }
    void printTree(){
        printTreeRec(root);
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

    tree.printTree();

    return 0;
}