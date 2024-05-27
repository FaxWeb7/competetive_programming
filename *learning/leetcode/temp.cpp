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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 && !list2) return nullptr;

    ListNode* res = new ListNode();
    if (list1 && list2) {
        if (list1->val < list2->val){
            res->val = list1->val;
            list1 = list1->next;
        } else {
            res->val = list2->val;
            list2 = list2->next;
        }
    }
    else if (list1) {
        res->val = list1->val;
        list1 = list1->next;
    }
    else if (list2) {
        res->val = list2->val;
        list2 = list2->next;
    }

    res->next = mergeTwoLists(list1, list2);

    return res;
}

int main(){
    ListNode* list1 = new ListNode(1);
    ListNode* l1n = new ListNode(2);
    ListNode* l1nn = new ListNode(3);
    l1n->next = l1nn;
    list1->next = l1n;

    ListNode* list2 = new ListNode(1);
    ListNode* l2n = new ListNode(3);
    ListNode* l2nn = new ListNode(4);
    l2n->next = l2nn;
    list2->next = l2n;

    ListNode* res = mergeTwoLists(list1, list2);
    while (res) {
        cout << res->val << ' ';
        res = res->next;
    }

    return 0;
}