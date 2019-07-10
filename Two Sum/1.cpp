/**
* @date: 19-5-29
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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> helpMap;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); ++i)
        {
            helpMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = target - nums[i];
            if (helpMap.count(tmp) && helpMap[tmp] != i)
            {
                res[0] = i;
                res[1] = helpMap[tmp];
                break;
            }
        }
        return res;

    }
};

int main() {
    Solution a;
    vector<int> input{0,4,3,0};
    auto res = a.twoSum(input,0);
    return 0;

}
