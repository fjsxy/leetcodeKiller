/**
* @date: 19-6-13
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
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        
        map<int,int> helpMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            helpMap[nums[i]]++;
        }
        
        int i = 0;
        while(!helpMap.empty())
        {
            auto iter = helpMap.begin();
            nums[i] = iter->first;
            iter->second --;
            if (iter->second == 0)
                helpMap.erase(iter);
            i++;
        }
    }
};

int main() {
    Solution a;
    vector<int> input{2,1,2,3,0,0,2};
    a.sortColors(input);
    cout << "1" << endl;
    return 0;
}
