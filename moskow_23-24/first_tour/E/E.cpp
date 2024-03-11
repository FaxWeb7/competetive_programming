#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    char letter;
    string code;
    Node* left;
    Node* right;

    Node(char l, string c) : letter(l), code(c), left(nullptr), right(nullptr) {}
};

void buildTree(Node* root, string& encoded, int& index) {
    if (index == encoded.size()) {
        return;
    }

    if (encoded[index] == '0') {
        if (root->left == nullptr) {
            root->left = new Node('\0', "");
        }
        index++;
        buildTree(root->left, encoded, index);
    } else if (encoded[index] == '1') {
        if (root->right == nullptr) {
            root->right = new Node('\0', "");
        }
        index++;
        buildTree(root->right, encoded, index);
    }
}

void traverseTree(Node* root, string code, map<char, string>& encoding) {
    if (root == nullptr) {
        return;
    }

    code += root->code;
    if (root->letter != '\0') {
        encoding[root->letter] = code;
    }

    traverseTree(root->left, code, encoding);
    traverseTree(root->right, code, encoding);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string original, encoded;
        cin >> original >> encoded;

        Node* root = new Node('\0', "");
        int index = 0;
        buildTree(root, encoded, index);

        map<char, string> encoding;
        traverseTree(root, "", encoding);

        for (char letter : original) {
            cout << letter << " " << encoding[letter] << endl;
        }

        cout << endl;

        // Очистка памяти
        delete root;
    }

    return 0;
}