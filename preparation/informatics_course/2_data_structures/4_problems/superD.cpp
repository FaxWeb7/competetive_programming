#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

//link to problem: http://poj.org/problem?id=3580
mt19937 randNum(123);

struct Node{
    int priority = randNum(), size = 1, val, minVal, add = 0, rev = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val) :  val(val), minVal(val){};
};

struct ImplicitTreap{
private:
    Node* root = nullptr;

    int getSize(Node* root){
        return root ? root->size : 0;
    }

    int getMinVal(Node* root){
        return root ? root->minVal+root->add : 2E9;
    }

    void update(Node* root){
        if (!root) return;
        root->size = getSize(root->left) + 1 + getSize(root->right);
        root->minVal = min(min(getMinVal(root->left), root->val), getMinVal(root->right));
    }

    void pushData(Node* root){
        if (!root) return;
        if (root->val){
            root->val += root->add;
            root->minVal += root->add;
            if (root->left) {
                root->left->add += root->add;
            }
            if (root->right) {
                root->right->add += root->add;
            }
            root->add = 0;
        }
        if (root->rev){
            swap(root->left, root->right);
            if (root->left){
                root->left->rev ^= 1;
            }
            if (root->right){
                root->right->rev ^= 1;
            }
            root->rev = 0;
        }
    }

    Node* merge(Node* L, Node* R){
        pushData(L);
        pushData(R);
        if (!L) return R;
        if (!R) return L;

        if (L->priority > R->priority){
            L->right = merge(L->right, R);
            update(L);
            return L;
        } else{
            R->left = merge(L, R->left);
            update(R);
            return R;
        }
    }

    void split(Node* root, int x, Node*& L, Node*& R){
        pushData(root);
        if (!root) L = R = nullptr;
        else if (getSize(root->left) < x){
            split(root->right, x - getSize(root->left) - 1, root->right, R);
            L = root;
        } else{
            split(root->left, x, L, root->left);
            R = root;
        }
        update(L);
        update(R);
    }

    void plusItems(Node*& root){
        if (!root) return;
        plusItems(root->left);
        root->val += 1;
        plusItems(root->right);
    }

public:
    void pushBack(int val){
        root = merge(root, new Node(val));
    }
    void insert(int index, int val){
        Node *left, *right;
        split(root, index, left, right);
        Node* newNode = new Node(val);
        root = merge(merge(left, newNode), right);
    }
    void remove(int index){
        Node* left, *mid, *right;
        split(root, index, left, right);
        split(right, 1, mid, right);
        root = merge(left, right);
    }
    void removeSegment(int from, int to){
        Node* left, *mid, *right;
        split(root, from, left, right);
        split(right, to-from+1, mid, right);
        root = merge(left, right);
    }
    void add(int x, int y, int d){
        Node *left, *mid, *right;
        split(root, x, left, right);
        split(right, y-x+1, mid, right);
        mid->add += d; 
        root = merge(merge(left, mid), right);
    }
    int getMin(int x, int y){
        Node *left, *mid, *right;
        split(root, x, left, right);
        split(right, y-x+1, mid, right);
        int ans = getMinVal(mid);
        root = merge(merge(left, mid), right);
        return ans;
    }
    void revolve(int x, int y, int t){
        Node *left, *mid, *right;
        split(root, x, left, right);
        split(right, y-x+1, mid, right);

        Node *leftM, *rightM;
        int len = getSize(mid);
        split(mid, len-(t%len), leftM, rightM);
        mid = merge(rightM, leftM);

        root = merge(merge(left, mid), right);
    }
    void reverse(int x, int y){
        Node *left, *mid, *right;
        split(root, x, left, right);
        split(right, y-x+1, mid, right);
        mid->rev ^= 1;
        root = merge(merge(left, mid), right);
    }
    int get(int index){
        Node *left, *mid, *right;
        split(root, index, left, right);
        split(right, 1, mid, right);
        root = merge(merge(left, mid), right);
        return mid->val;
    }
};

int main(){
    int n, m;
    cin >> n;

    ImplicitTreap treap;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        treap.pushBack(val);
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        string command;
        cin >> command;
        if (command == "INSERT"){
            int x, p;
            cin >> x >> p;
            treap.insert(x, p);
            for (int j = 0; j < n; j++){
                cout << treap.get(j) << " ";
            }
            cout << endl;
        } 
        else if (command == "DELETE"){
            int x;
            cin >> x;
            treap.remove(x-1);
            for (int j = 0; j < n; j++){
                cout << treap.get(j) << " ";
            }
            cout << endl;
        }
        else if (command == "ADD"){
            int x, y, d;
            cin >> x >> y >> d;
            treap.add(x-1, y-1, d);
            for (int j = 0; j < n; j++){
                cout << treap.get(j) << " ";
            }
            cout << endl;
        }
        else if (command == "MIN"){
            int x, y;
            cin >> x >> y;
            cout << treap.getMin(x-1, y-1) << endl;
        }
        else if (command == "REVOLVE"){
            int x, y, t;
            cin >> x >> y >> t;
            treap.revolve(x-1, y-1, t);
            for (int j = 0; j < n; j++){
                cout << treap.get(j) << " ";
            }
            cout << endl;
        }
        else if (command == "REVERSE"){
            int x, y;
            cin >> x >> y;
            treap.reverse(x-1, y-1);
            for (int j = 0; j < n; j++){
                cout << treap.get(j) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
