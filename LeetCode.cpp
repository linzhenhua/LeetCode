#include "LeetCode.h"

/*
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
vector<int> TowSum::twoSum(vector<int>& nums, int target)
{
    vector<int> tmp;

    //过滤大于target的数
    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
    {
        if(*iter < target)
        {
            tmp.push_back(*iter);
        }
    }

    //cout << "tmp:" << endl;
    //copy(tmp.begin(), tmp.end(), ostream_iterator<int>(cout, " ") );    //2,7

    vector<int> result;

    //[2, 7]
    for(vector<int>::iterator iter = tmp.begin(); iter != tmp.end();)
    {
        iter;       //has bug
        for(vector<int>::iterator i = iter; i != tmp.end(); ++i)
        {
            cout << "*i: " << *i << endl;
            cout << "*iter: " << *iter << endl;
            if(target == *iter + *i)
            {
                result.push_back(*iter);
                result.push_back(*i);
            }
        }
    }

    cout << "TowSum::result:" << endl;
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " ") );

    return result;
}

void testTowSum()
{
    int target = 9;
    int arr[] = {2, 7, 11, 15};
    vector<int> vec(arr, arr+4);

    TowSum ts;
    vector<int> result;

    result = ts.twoSum(vec, target);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " ") );
}


