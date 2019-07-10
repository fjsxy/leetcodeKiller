/**
* @date: 19-5-27
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
    int majorityElement(vector<int>& nums) {
        map<int,int> helpMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            helpMap[nums[i]]++;
        }

        int res = 0;
        for (auto &i : helpMap)
        {
            if (i.second > nums.size() / 2)
            {
                res = i.first;
                break;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {

    }
};

int main() {

}
