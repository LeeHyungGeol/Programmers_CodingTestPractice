// 구현, dfs(재귀 사용) 문제

#include <string>
#include <vector>

using namespace std;

int isBalanced(string str);
bool isProper(string str);

string solution(string p) {
    string answer = "";

    if (p.empty()) {
        return answer;
    }

    int index = isBalanced(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);

    if (isProper(u)) {
        return u + solution(v);
    }
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u.erase(u.begin());
        u.pop_back();

        for (int i = 0; i < u.length(); ++i) {
            if (u[i] == '(') {
                u[i] = ')';
            }
            else {
                u[i] = '(';
            }
        }
        answer += u;
    }

    return answer;
}

int isBalanced(string str) {
    int cnt = 0;

    for (int i = 0; i < str.length(); ++i) {
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

    for (int i = 0; i < str.length(); ++i) {
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