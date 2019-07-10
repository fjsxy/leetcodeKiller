/**
* @date: 19-5-15
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

class Solution {
public:
    int findIndexi(const vector<int>& nums)
    {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] > nums[i+1])
            i--;
        return i;
    }
    int findIndexj(const vector<int>& nums,int start)
    {
        int i = start + 1;
        while (i < nums.size() && nums[i] > nums[start])
        {
            i++;
        }
        return (i > start + 1 ? i - 1 : start + 1);
    }
    void Swap(vector<int>& nums,int index1,int index2)
    {
        int tmp = nums[index2];
        nums[index2] = nums[index1];
        nums[index1] = tmp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        res.push_back(nums);
        int i = findIndexi(nums);
        while(i >= 0)
        {
            int j = findIndexj(nums,i);
            Swap(nums,i,j);
            reverse(nums.begin() + i + 1,nums.end());
            res.push_back(nums);
            i = findIndexi(nums);
        }
        return res;
    }
};

class Solution2{
public:
    vector<vector<int>> permute(vector<int>& nums){

    }
};

void print0(const int& a)
{
    cout << a << " ";
}

void print1(const vector<int>& a)
{
    for_each(a.begin(),a.end(),print0);
    cout << endl;
}

int main() {
    vector<int> input{1,2,3};
    Solution a;
    auto res = a.permute(input);
    for_each(res.begin(),res.end(),print1);
    return 0;
}
