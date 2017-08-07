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

//Reverse digits of an integer.
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
int ReverseInteger::reverseInteger(int x)
{
    if(x >= 0)
    {
        stringstream sstr;
        string str;

        sstr << x;

        str = sstr.str();

        reverse(str.begin(), str.end());

        //input 1534236469
        long long ret;
        ret = atoll(str.c_str());

        //cout << ret << endl;
        //cout << "INT_MAX: " << INT_MAX << endl;

        if(ret < INT_MIN || ret > INT_MAX)
        {
            return 0;
        }

        return ret;
    }
    else   //x < 0
    {
        stringstream sstr;
        string str;

        sstr << x;

        str = sstr.str();

        //string str1;

        //copy(str.begin()+1, str.end(), back_inserter(str1) );

        //reverse(str1.begin(), str1.end());

        //str1.insert(str1.begin(), '-');

        //cout << "str1: " << str1 << endl;

        reverse(str.begin()+1, str.end());

        long long ret;
        ret = atoll(str.c_str());

        if(ret < INT_MIN || ret > INT_MAX)
        {
            return 0;
        }

        return ret;
    }
}

void testReverseInteger()
{
    ReverseInteger RI;

    int x = 1534236469;

    x = RI.reverseInteger(x);

    cout << x << endl;
}















































