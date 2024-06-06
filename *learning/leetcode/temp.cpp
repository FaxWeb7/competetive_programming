#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>

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


class Solution {
    int getDepth(ListNode* head){
        if (!head) return 0;
        int depth = 1;
        while (head->next){
            head = head->next;
            depth++;
        }
        return depth;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int depth = getDepth(head);

        int curDepth = 1;
        ListNode* removeItem = head;
        while (curDepth != depth-n+1) {
            removeItem = removeItem->next;
            curDepth++;
        }

        removeItem = removeItem->next;
        removeItem->val = -1;
        return head;
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