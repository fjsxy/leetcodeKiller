/**
* @date: 19-6-13
* @author: fjsxy
* @type: leetcode
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum = nums[i];
            if (sum == k)
                res++;
            for (int j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> helpMap;
        helpMap[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += helpMap[sum - k];
            helpMap[sum]++;
        }

        return res;
    }
};

int main() {
    Solution2 a;
    vector<int> input{1,1,1};
    cout << a.subarraySum(input,2) << endl;
    return 0;
}
