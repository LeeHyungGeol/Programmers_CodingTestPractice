#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int index;

bool comp(string s1, string s2) {
    return (s1[index] == s2[index]) ? s1 < s2 : s1[index] < s2[index];
}
vector<string> solution(vector<string> strings, int n) {
    index = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}