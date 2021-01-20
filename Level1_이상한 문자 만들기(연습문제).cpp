//문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 
//각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 
//각 단어의 짝수번째 알파벳은 대문자로, 
//홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.
//s : try hello world,  return : TrY HeLlO WoRlD
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            (cnt % 2 == 0) ? answer += toupper(s[i]) : answer += tolower(s[i]);
            cnt++;

        }
        else { answer += " "; cnt = 0; }
    }
    return answer;
}
string solution2(string s) {
    string answer = "";
    int nIndex = 1;
    for (int i = 0; i < s.size(); i++, nIndex++)
    {
        if (s[i] == ' ')
        {
            nIndex = 0;
            answer += " ";
        }
        else
            nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}