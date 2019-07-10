/**
* @date: 19-5-24
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
    void Swap(vector<int>& nums, int lhs,int rhs)
    {
        int tmp = nums[lhs];
        nums[lhs] = nums[rhs];
        nums[rhs] = tmp;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty())
            return vector<int>();

        int i = 0;
        while(i < nums.size())
        {
            if (nums[i] != 0 && nums[i] != i + 1)
            {
                if (nums[i] != nums[nums[i]-1])
                    Swap(nums,i,nums[i]-1);
                else
                {
                    nums[i] = 0;
                    i++;
                }
            }
            else
                i++;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                res.push_back(i+1);
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> input{1,1,2};
    auto res = a.findDisappearedNumbers(input);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    return 0;
}
