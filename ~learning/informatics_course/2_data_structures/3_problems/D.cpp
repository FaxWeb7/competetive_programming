#include <iostream>
#include <vector>
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
    vector<int> arrTree;

    Node* insertRec(Node* root, int val){
        if (root == nullptr){
            return new Node(val);
        }
        if (val < root->key){
            root->left = insertRec(root->left, val);
        }
        else if (val > root->key){
            root->right = insertRec(root->right, val);
        }
        return root;
    }

    Node* createArrayRec(Node* root){
        if (root != nullptr){
            createArrayRec(root->left);
            arrTree.push_back(root->key);
            createArrayRec(root->right);
        }
        return nullptr;
    }

public:
    void insert(int val){
        root = insertRec(root, val);
    }
    vector<int> createArray(){
        createArrayRec(root);
        return arrTree;
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

    vector<int> treeArr = tree.createArray();
    for (int num : treeArr) cout << num << endl;

    return 0;
}