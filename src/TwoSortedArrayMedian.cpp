#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>

using namespace std;

TODO class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double res = 0.0;
        //copy(nums1.begin(), nums1.end(), nums2.begin());
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sz = nums2.size();
        res = (sz % 2) ? nums2[sz / 2] : (nums2[sz / 2 - 1] + nums2[sz / 2]) / 2.0;
        return res;
    }
};

int main()
{
    vector<int> num1{2}, num2{};
    Solution solution;

    cout << endl
         << solution.findMedianSortedArrays(num1, num2) << endl;

    return 0;
}