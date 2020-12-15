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
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
            return 0;
        int area = (height.size() - 1) * min(height[0], height[height.size() - 1]);
        for (int i = 0, j = height.size() - 1; i != j;)
        {
            int h = min(height[i], height[j]);
            area = max(area, (j - 1) * h);
            if (height[i] < height[j])
                area = max(area, (j - i) * height[i++]);
            else
                area = max(area, (j - i) * height[j--]);
        }
        return area;
    }
};

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    cout << solution.maxArea(height) << endl;

    return 0;
}