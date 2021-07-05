//https://jhnyang.tistory.com/116

// DFS, 구현이라고 볼 수 있는 문제
// 구현에 조금 더 가까우나 DFS의 핵심인 재귀를 썼다는 거에 있어서 DFS라고 볼 수 있겠다.

#include <string>
#include <vector>

using namespace std;

int isBalanced(string str);
bool isProper(string str);

string solution(string p) {
    string answer = "";

    if (p.size() == 0) {
        return answer;
    }
    int index = isBalanced(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);

    if (isProper(u)) {
        return u + solution(v);
    }
    else {
        answer += "(";
        answer += solution(v);
        answer += ")";

        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == '(') {
                u[i] = ')';
            }
            else {
                u[i] = '(';
            }
        }

        answer += u;
        return answer;
    }
}

int isBalanced(string str) {
    int cnt = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            ++cnt;
        }
        else {
            --cnt;
        }
        if (cnt == 0) {
            return i;
        }
    }
}

bool isProper(string str) {
    int cnt = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            ++cnt;
        }
        else {
            --cnt;
            if (cnt == 0) {
                return true;
            }
        }
    }

    return false;
}
