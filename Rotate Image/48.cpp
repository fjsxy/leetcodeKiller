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
    void Swap(vector<vector<int>>& matrix,int index11,int index12,int index21,int index22)
    {
        int tmp = matrix[index11][index12];
        matrix[index11][index12] = matrix[index21][index22];
        matrix[index21][index22] = tmp;
    }
    void rotate(vector<vector<int>>& matrix) {
        auto size = matrix.size();
        for (int i = 0; i < size; ++i)//转置矩阵
        {
            for (int j = i + 1; j < size; ++j)
            {
                Swap(matrix,i,j,j,i);
            }
        }

        for (int j = 0; j < size / 2; ++j)//将第一列与最后一列交换，重复
        {
            for (int i = 0; i < size; ++i)
            {
                Swap(matrix,i,j,i,size - j - 1);
            }
        }
    }
};

int main() {

}
