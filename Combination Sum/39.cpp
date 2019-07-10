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
    void combinationDFS(const vector<int>& candidates,int target, int start,
            vector<int>& out,vector<vector<int>>& res){
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(out);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            out.push_back(candidates[i]);
            combinationDFS(candidates,target - candidates[i],i,out,res);
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        combinationDFS(candidates,target,0,out,res);

        return res;
    }
};

int main() {
    Solution a;
    vector<int> input{2,3,5};
    auto res = a.combinationSum(input,8);
    return 0;
}
