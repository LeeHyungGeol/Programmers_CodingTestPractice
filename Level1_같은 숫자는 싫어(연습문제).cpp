#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}