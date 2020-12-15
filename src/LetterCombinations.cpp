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
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return {};
        unordered_map<char, string> digi;
        digi['2'] = "abc";
        digi['3'] = "def";
        digi['4'] = "ghi";
        digi['5'] = "jkl";
        digi['6'] = "mno";
        digi['7'] = "pqrs";
        digi['8'] = "tuv";
        digi['9'] = "wxyz";

        vector<string> res;
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            int num = digits[i] - '0';
            if (num < 0 || num > 9)
                break;
            const string &candinate = digi[digits[i]];
            vector<string> tmp;
            for (int j = 0; j < candinate.size(); ++j)
            {
                for (int k = 0; k < res.size(); ++k)
                {
                    tmp.push_back(res[k] + candinate[j]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};

int main()
{
    string digits = "23";
    Solution solution;
    vector<string> res = solution.letterCombinations(digits);
    for (const auto &item : res)
        cout << item << " ";

    return 0;
}