#ifndef LEET_CODE_H
#define LEET_CODE_H

#include <cstdio>
#include <cstdlib>
#include <climits>

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class TowSum {
public:
    vector<int> twoSum(vector<int>& nums, int target);
};

void testTowSum();

class ReverseInteger{
public:
    int reverseInteger(int x);
};

void testReverseInteger();

#endif // LEET_CODE_H
