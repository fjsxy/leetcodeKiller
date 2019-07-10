/**
 * @date: 19-5-4
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

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if (S.empty() || J.empty())
            return 0;
        map<char,int> helpMap;
        for (int i = 0; i < S.size(); ++i)
        {
            helpMap[S[i]]++;
        }

        int res = 0;
        for (int j = 0; j < J.size(); ++j) {
            res += helpMap[J[j]];
        }
        return res;
    }
};

int main() {
    Solution a;
    cout << a.numJewelsInStones("aA","aAAbbbb");
}
