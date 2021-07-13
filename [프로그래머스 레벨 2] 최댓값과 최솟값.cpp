#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss;
    vector<int> nums;
    int num;

    ss.str(s);

    while (ss >> num) {
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    answer += to_string(nums[0]) + " ";
    answer += to_string(nums[nums.size() - 1]);

    return answer;
}