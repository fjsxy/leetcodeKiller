/**
* @date: 19-5-28
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
    int findDuplicate(vector<int>& nums) {
        int start = 1,end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int count = 0;
            for (int i = 0 ;i < nums.size(); ++i)
            {
                if (nums[i] <= mid)
                    count++;
            }
            if (count > mid)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
};

class Solution2{//链表环的概念
public:
    int findDuplicate(vector<int>& nums)
    {
        int index1 = 0,index2 = 0;
        do{
            index1 = nums[index1];
            index2 = nums[nums[index2]];
        }while(index1 != index2);

        index1 = 0;
        do{
            index1 = nums[index1];
            index2 = nums[index2];
        }while(index1 != index2);

        return index1;
    }
};

int main() {
    Solution a;
    Solution2 b;
    vector<int> input{1,3,4,2,2};
    cout << a.findDuplicate(input) << endl;
    cout << b.findDuplicate(input) << endl;
}
