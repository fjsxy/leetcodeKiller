/**
* @date: 19-6-14
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
    void DFS(const vector<int>& nums,int index,int& res,int curSum, int target)
    {
        if (index == nums.size())
        {
            if (curSum == target)
                res++;
        }
        else
        {
            DFS(nums,index + 1,res,curSum + nums[index],target);
            DFS(nums,index + 1,res,curSum - nums[index],target);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int res;
        DFS(nums,0,res,0,S);
        return res;
    }
};

int main() {

}
