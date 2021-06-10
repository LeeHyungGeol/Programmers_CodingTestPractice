//https://jhnyang.tistory.com/116

// DFS, �����̶�� �� �� �ִ� ����
// ������ ���� �� ����쳪 DFS�� �ٽ��� ��͸� ��ٴ� �ſ� �־ DFS��� �� �� �ְڴ�.

#include <string>
#include <vector>

using namespace std;

int isBalanced(string s);
bool isProper(string s);

string solution(string p) {
    string answer = "";
    if (p == "") {
        return p;
    }
    int index = isBalanced(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);

    if (isProper(u)) {
        return u + solution(v);
    }
    else {
        string tmp = "(";
        tmp += solution(v);
        tmp += ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(') {
                u[i] = ')';
            }
            else {
                u[i] = '(';
            }
        }
        tmp += u;
        return tmp;
    }
    //return answer;
}

int isBalanced(string s) {
    int count = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++count;
        }
        else {
            --count;
        }
        if (count == 0) {
            return i;
        }
    }

    // return -1;
}

bool isProper(string s) {
    int count = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++count;
        }
        else {
            if (count == 0) {
                return false;
            }
            --count;
        }
    }

    return true;
}