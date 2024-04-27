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
    bool isBalance = true;

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

    int maxDepth(Node* root){
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }

    void checkBalanceRec(Node* root){
        if (root == nullptr) return;

        int leftItems = maxDepth(root->left);
        int rightItems = maxDepth(root->right);
        if (abs(rightItems-leftItems) > 1){
            isBalance = false;
            return;
        }
        checkBalanceRec(root->left);
        checkBalanceRec(root->right);
    }

public:
    void insert(int val){
        root = insertRec(root, val);
    }
    bool checkBalance(){
        checkBalanceRec(root);
        return isBalance;
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

    cout << (tree.checkBalance() ? "YES" : "NO");

    return 0;
}