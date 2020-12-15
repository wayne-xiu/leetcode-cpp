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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int sz = nums.size();
        if (sz < 3)
            return 0;
        int closet = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end()); // sort
        for (int first = 0; first < sz - 2; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue; // skip duplicates
            int second = first + 1;
            int third = sz - 1;
            while (second < third)
            {
                int cursum = nums[first] + nums[second] + nums[third];
                if (cursum == target)
                    return cursum;
                if (abs(target - cursum) < abs(target - closet))
                    closet = cursum;
                if (cursum > target)
                    --third;
                else
                    ++second;
            }
        }
        return closet;
    }
};

int main()
{
    vector<int> nums = {-1, 2, -1, 1, -4};
    Solution solution;
    int target = 1;
    int res = solution.threeSumClosest(nums, target);

    cout << res << endl;

    return 0;
}