#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>
#include <chrono>
#include <cassert>
#include <cmath>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strin)
    {
        string res;
        if (strin.empty())
            return res;
        int len = 1000;
        for (auto &stri : strin)
            len = (len > stri.size()) ? stri.size() : len;
        for (auto i = 0; i < len; ++i)
        {
            char c = strin[0][i];
            for (auto j = 1; j < strin.size(); j++)
            {
                if (strin[j][i] != c)
                    return res;
            }
            res += c;
        }
        return res;
    }
};

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;

    return 0;
}