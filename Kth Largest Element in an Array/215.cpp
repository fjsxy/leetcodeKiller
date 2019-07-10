/**
* @date: 19-5-30
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> helpQue(nums.begin(),nums.end());
        int res;
        for (int i = 0; i < k; ++i)
        {
            res = helpQue.top();
            helpQue.pop();
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> input{3,2,3,1,2,4,5,5,6};
    cout << a.findKthLargest(input,4) << endl;
}
