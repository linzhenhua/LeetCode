#include "LeetCode.h"

/*
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
vector<int> TowSum::twoSum(vector<int>& nums, int target)
{
    vector<int> result;

    //[2, 7, 11, 15]
    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
    {
        for(vector<int>::iterator i = iter+1; i != nums.end(); ++i)
        {
            if(target == *iter + *i)
            {
                int x = distance(nums.begin(), i);
                int y = distance(nums.begin(), iter);
                result.push_back(x);
                result.push_back(y);
            }
        }
    }
    return result;
}

void testTowSum()
{
    int target = 9;
    int arr[] = {2, 7, 11, 15, 3, 6, 1, 8};
    vector<int> vec(arr, arr+8);

    TowSum ts;
    vector<int> result;

    result = ts.twoSum(vec, target);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " ") );
}


