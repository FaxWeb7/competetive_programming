#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<string, int> si;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(ListNode* root) {
        vector<vector<int>> res;
        
        queue<ListNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> vec;
            int cnt = q.size();
            for (int i = 0; i < cnt; ++i)
                ListNode* v = q.front();
                q.pop();

                vec.push_back(v->val);
                if (v->left) q.push(v->left);
                if (v->right) q.push(v->right);
            }

            res.push_back(vec);
        }

        return res;
    }
};

int main(){
    string n1, n2; cin >> n1 >> n2;

    if (n2.size() > n1.size()) swap(n1, n2);
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    while (n2.size() != n1.size()) n2 = '0' + n2;

    string n = "";
    int rem = 0;
    for (int i = n1.size()-1; i >= 0; --i){
        int x = (n1[i] - '0') + (n2[i] - '0') + rem;
        if (x >= 10) {
            rem = x / 10;
            x -= (rem * 10);
        } else rem = 0;
        n = to_string(x) + n;
    }
    // reverse(n.begin(), n.end());

    cout << n;

    return 0;
}