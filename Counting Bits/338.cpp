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
    int count(int num){
        int count = 0;
        while(num != 0)
        {
            num &= (num - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i =0; i <= num; ++i)
        {
            if (i == 0)
                res.push_back(0);
            else
                res.push_back(count(i));
        }
        return res;
    }
};

class Solution2{
public:
    int findRange(int num){
        int count = 0;
        while(num >= pow(2,count))
        {
            count++;
        }
        return count - 1;
    }
    vector<int> countBits(int num){
        vector<int> res{0};
        if (num == 0)
            return res;

        res.push_back(1);
        for (int i = 2; i <= num; ++i)
        {
            int regionNum = findRange(i);
            int numInRegion = pow(2,regionNum);
            if (i - numInRegion < numInRegion / 2)
            {
                res.push_back(res[i - pow(2,regionNum - 1)]);
            }
            else
            {
                res.push_back(res[i - pow(2,regionNum - 1)] + 1);
            }
        }
        return res;
    }
};

class Solution3{
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1,0);

        for (int i = 1; i <= num; ++i) {
            res[i] = res[i / 2] + i % 2;
        }
        return res;
    }
};

int main() {
    Solution3 a;
    auto b = a.countBits(15);
    auto iter = b.begin();
    while (iter != b.end())
    {
        cout << *iter << endl;
        iter++;
    }
}
