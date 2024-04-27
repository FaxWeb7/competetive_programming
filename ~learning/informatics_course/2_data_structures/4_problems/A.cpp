#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    int priority;
    int nodeN;
    Node* parent;
    Node* left;
    Node* right;

    Node(int key, int priority, int nodeN){
        this->key = key;
        this->priority = priority;
        this->nodeN = nodeN;
        parent = left = right = nullptr;
    }
};

struct Treap{
private:
    Node* root = nullptr;

    void update(Node* root){
        if (!root) return;
        if (root->left) root->left->parent = root;
        if (root->right) root->right->parent = root;
    }

    Node* mergeRec(Node* L, Node* R){
        if (!L) return R;
        if (!R) return L;
        if (L->priority < R->priority){
            L->right = mergeRec(L->right, R);
            update(L);
            return L;
        }
        else{
            R->left = mergeRec(L, R->left);
            update(R);
            return R;
        }
    }

    void splitRec(Node* root, int val, Node*& L, Node*& R){
        if (!root) L = R = nullptr;
        else if (root->key <= val){
            splitRec(root->right, val, root->right, R);
            L = root;
        }
        else {
            splitRec(root->left, val, L, root->left);
            R = root;
        }
        update(L);
        update(R);
    }

    Node* find(Node* root, int val){
        if (root == nullptr || root->key == val) return root;
        if (root->key < val){
            return find(root->right, val);
        } else {
            return find(root->left, val);
        }
    }

public:
    void insert(int val, int priority, int nodeN){
        Node *left, *right;
        splitRec(root, val, left, right);
        Node* newNode = new Node(val, priority, nodeN);
        if (left) left->parent = newNode;
        if (right) right->parent = newNode;
        root = mergeRec(mergeRec(left, newNode), right);
        root->parent = nullptr;
    }

    Node getNode(int val){
        Node* node = find(root, val);
        return *node;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Treap treap;
    int n, x, y;
    cin >> n;
    vector<int> values;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        treap.insert(x, y, i+1);
        values.push_back(x);
    }

    cout << "YES" << endl;
    for (int val : values){
        Node node = treap.getNode(val);
        cout << (node.parent ? node.parent->nodeN : 0) << " " << (node.left ? node.left->nodeN : 0) << " " << (node.right ? node.right->nodeN : 0) << endl;
    }
    
    return 0;
}