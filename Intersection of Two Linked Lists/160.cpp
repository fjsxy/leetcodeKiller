/**
* @date: 19-7-11
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

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;

        ListNode* pa = headA,*pb = headB;
        int lenA = 1, lenB = 1;
        while (pa != NULL)
        {
            pa = pa->next;
            lenA++;
        }
        while (pb != NULL)
        {
            pb = pb->next;
            lenB++;
        }
        ListNode* pl = (lenA > lenB ? headA : headB);
        ListNode* ps = (lenA > lenB ? headB : headA);
        int i = abs(lenA - lenB);
        while(i > 0)
        {
            pl = pl->next;
            i--;
        }
        while(pl != NULL && ps != NULL)
        {
            if (pl == ps)
                return pl;
            pl = pl->next;
            ps = ps->next;
        }
        return NULL;
    }
};

int main() {

}
