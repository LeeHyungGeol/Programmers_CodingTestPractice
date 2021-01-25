#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    for (int i = 0; i < new_id.size(); ++i) {
        new_id[i] = tolower(new_id[i]);
        if ((48 <= new_id[i] && new_id[i] <= 57) ||
            (97 <= new_id[i] && new_id[i] <= 122) ||
            new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            tmp += new_id[i];
        }
    }
    char c = '.';
    tmp.erase(unique(tmp.begin(), tmp.end(),
        [=](const auto& c1, const auto& c2) { return c1 == c && c1 == c2; }),
        tmp.end());
    if (tmp.front() == '.') tmp.erase(tmp.begin() + 0);
    if (tmp.back() == '.') tmp.erase(tmp.begin() + (tmp.size() - 1));
    if (tmp.empty()) tmp.assign("a");
    if (tmp.size() >= 16) {
        tmp.erase(tmp.begin() + 15, tmp.end());
        if (tmp[tmp.size() - 1] == '.') tmp.pop_back();
    }
    if (tmp.size() <= 2) {
        while (tmp.size() < 3) {
            tmp += tmp.back();
        }
    }
    answer = tmp;
    return answer;
}
string solution2(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch : new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch : new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}
int main() {
    string s = "...bb.....bbbb..b.b.b..";
    cout << solution(s) << '\n';
    return 0;
}