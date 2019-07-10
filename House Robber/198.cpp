/**
* @date: 19-6-25
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
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size()+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i - 1]);
        }
        return dp.back();
    }
};

int main() {

}
