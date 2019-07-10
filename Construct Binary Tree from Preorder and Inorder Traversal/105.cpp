/**
* @date: 19-6-26
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
    int find(const vector<int>& inorder,int target,int start,int end)
    {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == target)
                return i;
        }
    }
    void AA(vector<int>& inorder,TreeNode* node,int start,int end,int target)
    {
        int index = find(inorder,target,start,end);
        TreeNode*
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;

        int tmp = preorder[0];
        TreeNode* root = new TreeNode(tmp);
        int index = find(inorder,tmp,0,inorder.size() - 1);
        for (int i = 1; i < preorder.size(); ++i) {
            AA(inorder,root,)
        }

    }
};

int main() {

}
