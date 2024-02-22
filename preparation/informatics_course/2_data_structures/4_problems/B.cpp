#include <iostream>
#include <random>
using namespace std;
using ll = long long;

mt19937 randNum(123);

struct Node{
    ll key;
    ll priority;
    Node* left;
    Node* right;

    Node(int val){
        key = val;
        priority = randNum();
        left = right = nullptr;
    }
};

struct Treap{
private:
    Node* root = nullptr;

    Node* mergeRec(Node* L, Node* R){
        if (!L) return R;
        if (!R) return L;

        if (L->priority > R->priority){
            L->right = mergeRec(L->right, R);
            return L;
        } else {
            R->left = mergeRec(L, R->left);
            return R;
        }
    }

    void splitRec(Node* root, ll x, Node*& L, Node*& R){
        if (root == nullptr) L = R = nullptr;
        else if (root->key <= x){
            splitRec(root->right, x, root->right, R);
            L = root;
        } else{
            splitRec(root->left, x, L, root->left);
            R= root;
        }
    }

    Node* findRec(Node* root, ll val){
        if (!root || root->key == val) return root;
        if (root->key < val) {
            return findRec(root->right, val);
        } else{
            return findRec(root->left, val);
        }
    }

    Node* getNext(Node* root, ll x){
        if (!root || root->key == x) return root;
        if (root->key < x) {
            return getNext(root->right, x);
        } else{
            Node* leftNode = getNext(root->left, x);
            if (leftNode){
                return leftNode;
            }
            return root;
        }
    }

public:
    void insert(ll val){
        if (findRec(root, val) != nullptr) return;
        Node *left, *right;
        splitRec(root, val, left, right);
        Node* newNode = new Node(val);
        root = mergeRec(mergeRec(left, newNode), right);
    }

    ll next(ll x){
        Node* nextNode = getNext(root, x);
        if (nextNode && nextNode->key >= x) {
            return nextNode->key;
        }
        return -1;
    }
};

int main(){
    int n;
    cin >> n;

    Treap treap;
    ll prevRes = 0;
    for (int i = 0; i < n; i++){
        char command;
        ll num;
        cin >> command >> num;
        if (command == '+'){
            treap.insert((num+prevRes)%(int)1E9);
            prevRes = 0;
        }
        else if (command == '?'){
            ll res = treap.next(num); 
            cout << res << endl;
            prevRes = res;
        }
    }

    return 0;
}
