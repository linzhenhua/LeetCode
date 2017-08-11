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

bool PalindromeNumber::isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }
    //12121
    int temp = x;
    int tmp = 0;

    //说明：
    //temp % 10求出个位，temp / 10求出除了个位之后的数，tmp *10使一个数进一位
    while(temp)
    {
        tmp = tmp *10 + temp % 10;

        temp = temp / 10;
    }

    if(x == tmp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void testPalindromeNumber()
{
    PalindromeNumber PN;
    int x = 0;

    bool flag = PN.isPalindrome(x);

    if(flag)
    {
        cout << "是回文数" << endl;
    }
    else
    {
        cout << "不是回文数" << endl;
    }
}

int RomanToInt::romanToInt(string s)
{
    int tagVal[256] = {0};

    tagVal['I'] = 1;
    tagVal['V'] = 5;
    tagVal['X'] = 10;
    tagVal['C'] = 100;
    tagVal['M'] = 1000;
    tagVal['L'] = 50;
    tagVal['D'] = 500;

    int val = 0;

    //s = "DCXXI"
    for(int i = 0; i < s.length(); i++)
    {
        if(i+1 >= s.length() || tagVal[s[i+1]] <= tagVal[s[i]])
            val += tagVal[s[i]];
        else
            val -= tagVal[s[i]];
    }

    return val;
}

void testRomanToInt()
{
    RomanToInt RTI;

    string str("DCXXI");

    int x = RTI.romanToInt(str);

    cout << x << endl;
}

string LongestCommonPrefix::longestCommonPrefix(vector<string>& strs)
{
    int n = strs.size();
    string res;

    if(n == 0)
        return res;

    for(int pos = 0; pos < strs[0].size(); pos++)   //最长前缀的长度不超过strs[0].size()，逐个字符的比较
    {
        for(int k = 1; k < n; k++)                  //strs[0]的第pos个字符分别和strs[1...n-1]的第pos个字符比较
        {
            if(strs[k].size() == pos || strs[k][pos] != strs[0][pos])
                return res;
        }
        res.push_back(strs[0][pos]);
    }

    return res;
}

void testLongestCommonPrefix()
{
    LongestCommonPrefix LCP;

    vector<string> vec;

    vec.reserve(5);

    vec.push_back("abc");
    vec.push_back("abcdef");
    vec.push_back("ab");
    vec.push_back("abcd");
    vec.push_back("ab");

    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " ") );
    cout << endl;

    string str = LCP.longestCommonPrefix(vec);

    cout << str << endl;
}








































