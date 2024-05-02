#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    bool terminal = 0;
};

class Trie {
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word) {
        Node* v = root;
        for (char c : word) {
            if (v->children[c] == nullptr) {
                v->children[c] = new Node();
            }
            v = v->children[c];
        }
        v->terminal = true;
    }

    bool search(string word) {
        Node* v = root;
        for (char c : word) {
            if (v->children[c] == nullptr) {
                return false;
            }
            v = v->children[c];
        }
        return v != nullptr && v->terminal;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;

    return 0;
}