/**
* @date: 19-5-23
* @author: fjsxy
* @type: leetcode
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverse(ListNode* head,ListNode*& trueHead){
        if (head->next == NULL)
        {
            trueHead = head;
            return head;
        }
        ListNode* tmp = reverse(head->next,trueHead);
        tmp->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* trueHead;
        reverse(head,trueHead);
        return trueHead;
    }
};

int main() {

}
