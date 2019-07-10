/**
* @date: 19-5-6
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
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = z;
        int count = 0;
        while(res != 0)
        {
            res = res & (res - 1);
            count ++;
        }
        return count;
    }
};

int main() {
    Solution a;
    cout << a.hammingDistance(1,4) << endl;
}
