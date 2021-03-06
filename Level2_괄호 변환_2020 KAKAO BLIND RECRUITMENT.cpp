#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
typedef pair<string, string> pss;

bool isValidPS(string str) {
    stack<char> stack;
    int cnt = 0;
    for (int j = 0; j < str.size(); j++) {
        if (str[j] == '(') {
            stack.push(str[j]);
            cnt++;
        }
        else {
            if (stack.empty()) {
                return false;
                cnt = -100;
                break;
            }
            stack.pop();
            cnt--;
        }
    }
    if (cnt == -100)
        return false;
    else if (cnt != 0)
        return false;
    else
        return true;
}
pss BalancedPS(string str) {
    stack<char> stack;
    string u = "";
    int cnt = 0, index = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '(') stack.push(str[i]);
        else cnt++;
        u += str[i];
        if (!stack.empty() && stack.size() == cnt) { index = ++i; break; }
    }
    string v = str.substr(index, str.size() - u.size());
    cout << u << '\n' << v << '\n';
    pss ret = { u,v };
    return ret;
}
string func(string s) {
    string answer = "";
    pss uv = { "","" };
    if (s == "") return s;
    if (isValidPS(s)) return s;
    uv = BalancedPS(s);
    //if(isValidPS(uv.first) && isValidPS(uv.second)) {
    //    answer+=uv.first; 
    //    answer+=uv.second;
    //    return answer;
    //}
    if (isValidPS(uv.first) && !isValidPS(uv.second)) {
        uv.second = func(uv.second);
        uv.first += uv.second;
        return uv.first;
    }
    if (!isValidPS(uv.first)) {
        string str = "";
        str += "(";
        uv.second = func(uv.second);
        str += uv.second;
        str += ")";
        uv.first.pop_back(); uv.first.erase(uv.first.begin());
        for (int i = 0; i < uv.first.size(); ++i) {
            if (uv.first[i] == '(') uv.first[i] = ')';
            else uv.first[i] = '(';
        }
        str += uv.first;
        return str;
    }
}
string solution(string p) {
    string answer = "";
    answer = func(p);

    return answer;
}