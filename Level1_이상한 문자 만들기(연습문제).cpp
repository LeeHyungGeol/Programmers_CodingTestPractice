//���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. 
//�� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. 
//�� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, 
//Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.
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