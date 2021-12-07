#include <string>
#include <vector>

using namespace std;

int isBalanced(string s);
bool isProper(string s);

string solution(string p) {
    string answer = "";

    if (p.empty()) return p;
    int index = isBalanced(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    if (isProper(u)) {
        return u + solution(v);
    }
    else {
        answer += "(" + solution(v) + ")";
        u.erase(u.begin());
        u.pop_back();
        for (int i = 0; i < u.length(); ++i) u[i] = (u[i] == '(') ? ')' : '(';
        answer += u;
        return answer;
    }
}

int isBalanced(string s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') ++cnt;
        else --cnt;
        if (cnt == 0) return i;
    }
    return -1;
}

bool isProper(string s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') ++cnt;
        else {
            --cnt;
            if (cnt == 0) return true;
        }
    }
    return false;
}