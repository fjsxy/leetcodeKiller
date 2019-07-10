/**
* @date: 19-6-5
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> helpMap;
        if (strs.empty())
            return res;

        for(auto &s : strs)
        {
            string tmp = s;
            sort(tmp.begin(),tmp.end());
            helpMap[tmp].push_back(s);
        }
        for (auto &i : helpMap)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

int main() {

}
