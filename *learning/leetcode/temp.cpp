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

    return 0;
}