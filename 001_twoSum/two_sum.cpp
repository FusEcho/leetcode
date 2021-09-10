#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp.count(target - nums[i]) > 0)
            {
                return {i, temp[target - nums[i]]};
            }
            else
            {
                temp[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    vector<int> a{3, 2, 4};
    Solution solution;
    vector<int> b = solution.twoSum(a, 6);
    for (auto i : b)
    {
        cout << i << endl;
    }
    return 0;
}