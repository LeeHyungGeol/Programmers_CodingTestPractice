#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int cntP = 0, cntY = 0;
    for (int i = 0; i < s.size(); ++i)
        s[i] = toupper(s[i]);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P') cntP++;
        else if (s[i] == 'Y') cntY++;
    }
    (cntP == cntY) ? answer = true : answer = false;
    return answer;
}