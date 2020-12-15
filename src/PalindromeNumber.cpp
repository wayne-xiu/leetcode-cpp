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

// class Solution
// {
// public:
//     bool isPalindrome(int x)
//     {
//         if (x < 0)
//             return false;
//         int xreverse = reverse(x);
//         return (x == xreverse);
//     }
//     int reverse(int x)
//     {
//         int res = 0;
//         while (x != 0)
//         {
//             int tail = x % 10;
//             x = x / 10;
//             if (res > INT_MAX / 10)
//                 return 0;
//             res = 10 * res + tail;
//         }
//         return res;
//     }
// };

class Solution
{
public:
    bool isPalindrome(int x)
    {

        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reverse = 0;
        while (x > reverse) // handling half; smart
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return x == reverse || x == reverse / 10;
    }
};

int main()
{
    int x = 1234567899;
    Solution solution;
    cout << solution.isPalindrome(x) << endl;
    return 0;
}