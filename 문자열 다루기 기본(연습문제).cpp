#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() == 4 || s.size() == 6) {
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] - '0') > 10) answer = false;
        }
    }
    else answer = false;
    return answer;
}
bool solution2(string s) {
    bool answer = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }

    return s.size() == 4 || s.size() == 6 ? answer : false;
}