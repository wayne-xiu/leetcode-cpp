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

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

template <typename F, typename... Args>
double funcTime(F func, Args &&... args)
{
    TimeVar t1 = timeNow();
    func(std::forward<Args>(args)...);
    return duration(timeNow() - t1);
}

// class Solution
// {
// public:
//     string convert(string s, int numRows)
//     {
//         if (numRows == 1)
//             return s;
//         vector<string> resStr(min(numRows, int(s.size())));
//         bool goingDown = false;
//         int curRow = 0;
//         for (char c : s)
//         {
//             resStr[curRow] += c;
//             if (curRow == 0 || curRow == numRows - 1)
//                 goingDown = !goingDown;
//             curRow += goingDown ? 1 : -1;
//         }
//         string res;
//         for (auto &str : resStr)
//         {
//             res += str;
//         }
//         return res;
//     }
// };

class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < n; j += cycleLen)
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};

int main()
{
    string s{"PAYPALISHIRING"};
    Solution solution;

    assert(solution.convert(s, 3) == string("PAHNAPLSIIGYIR"));
    assert(solution.convert(s, 4) == string("PINALSIGYAHRPI"));

    return 0;
}