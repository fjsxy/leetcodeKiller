/**
* @date: 19-5-23
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
    void Swap(vector<int>& nums,int lhs,int rhs){
        int tmp = nums[lhs];
        nums[lhs] = nums[rhs];
        nums[rhs] = tmp;
    }
    void moveZeroes(vector<int>& nums) {
        int zero_index = -1,non_zero_index = 0;
        bool flag = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0 )
            {
                if (zero_index == -1)
                    zero_index = i;
                else
                    zero_index = (zero_index < i ? zero_index : i);
            }
            else
            {
                non_zero_index = i;
                flag = false;
            }
            if (!flag && zero_index < non_zero_index && zero_index >= 0)
            {
                Swap(nums,zero_index,non_zero_index);
                zero_index++;
                flag = true;
            }
        }
    }
};

void print(const int& a)
{
    cout << a << " "  ;
}

int main() {
    Solution a;
    vector<int> input{0,1,0,3,12};
    a.moveZeroes(input);
    for_each(input.begin(),input.end(),print);

}
