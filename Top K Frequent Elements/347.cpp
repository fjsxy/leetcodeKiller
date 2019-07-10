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

class Solution {
public:
    struct Compare{
        bool operator() (const pair<int,int>& lhs,const pair<int,int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty())
            return vector<int>();
        map<int,int> help_map;
        for (int i = 0; i < nums.size(); ++i)
        {
            help_map[nums[i]]++;
        }
        vector<pair<int,int>> help_vec(help_map.begin(),help_map.end());
        sort(help_vec.begin(),help_vec.end(),Compare());
        vector<int> res(k);
        for (int i = 0; i < k; ++i)
        {
            res[i] = help_vec[i].first;
        }
        return res;
    }
};

class Solution2{
public:
    struct Compare{
        bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
            return lhs.second < rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k){
        if (nums.empty())
            return vector<int>();
        map<int,int> helpMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            helpMap[nums[i]] ++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int >>,Compare> helpProQue(helpMap.begin(),helpMap.end());
        vector<int> res(k);
        for (int j = 0; j < k; ++j) {
            res[j] = helpProQue.top().first;
            helpProQue.pop();
        }
        return res;
    }
};

void print(const int& a)
{
    cout << a << " ";
}

int main() {
    Solution a;
    Solution2 b;
    vector<int> input{1,1,1,2,2,3};
    auto res = b.topKFrequent(input,2);
    for_each(res.begin(),res.end(),print);
}
