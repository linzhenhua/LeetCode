#include "LeetCode.h"

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

        //cout << "x >= 0: " << str << endl;
        int ret;
        ret = atoi(str.c_str());

        return ret;
    }
    else   //x < 0
    {
        stringstream sstr;
        string str;

        sstr << x;

        str = sstr.str();

        string str1;

        copy(str.begin()+1, str.end(), back_inserter(str1) );

        reverse(str1.begin(), str1.end());

        str1.insert(str1.begin(), '-');

        //cout << "str1: " << str1 << endl;
        int ret;

        ret = atoi(str1.c_str());

        return ret;
    }
}

void testReverseInteger()
{
    ReverseInteger RI;

    int x = 123654;

    x = RI.reverseInteger(x);

    cout << x << endl;
}















































