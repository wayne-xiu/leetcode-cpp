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
//     int reverse(int x)
//     {
//         int sign = (x < 0) ? -1 : 1;
//         string xstr = to_string(abs(x));
//         reverse(xstr);
//         return sign * stoi(xstr);
//     }

// private:
//     void reverse(string &str)
//     {
//         if (str.size() == 1)
//             return;
//         for (int i = 0; i < str.size() / 2; i++)
//             swap(str[i], str[str.size() - 1 - i]);
//     }
// };

// class Solution
// {
// public:
//     int reverse(int x)
//     {
//         int rev = 0;
//         while (x != 0)
//         {
//             int pop = x % 10;
//             x /= 10;
//             if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
//                 return 0;
//             if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
//                 return 0;
//             rev = rev * 10 + pop;
//         }
//         return rev;
//     }
// };

class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        while (x != 0)
        {
            int tail = x % 10;
            int newResult = result * 10 + tail;
            if ((newResult - tail) / 10 != result)
                return 0;
            result = newResult;
            x = x / 10;
        }
        return result;
    }
};

int main()
{
    int x = 1534236469;
    Solution solution;
    cout << solution.reverse(x) << endl;

    return 0;
}