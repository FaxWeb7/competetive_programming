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
    int maxKey;

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

    Node* removeRec(Node* root, int val){
        if (root == nullptr) return nullptr;

        if (val == root->key){
            if (root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            root->key = getMax(root->left);
            root->left = removeRec(root->left, root->key);
            return root;
        }

        if (val < root->key) root->left = removeRec(root->left, val);
        if (val > root->key) root->right = removeRec(root->right, val);
        return root;
    }

    int getMax(Node* root){
        while (root->right != nullptr){
            root = root->right;
        }
        return root->key;
    }


public:
    void insert(int val){
        root = insertRec(root, val);
    }
    int getMax(){
        int maxKey = getMax(root);
        root = removeRec(root, maxKey);
        int secondMaxKey = getMax(root);
        return secondMaxKey;
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

    cout << tree.getMax();

    return 0;
}