// 자료구조, stack문제
// 올바른 괄호 문자열인지 파악하는 문제

// 올바른 괄호인지 판단할 때 가장 중요한 것은 "가장 최근에 나온 여는 괄호" 이다.
// 탐색을 함에 있어서 "가장 최근에 나온 여는 괄호" 에 대한 정보를 계속해서 저장

// 1. Stack을 통해서 "여는 괄호"들을 관리할 것이다.
// 2. "닫는 괄호"를 만나게 되면, Stack의 top()에 있는 "여는 괄호"를 가져오고 비교
//  2-1. stack이 비어있거나, "여는 괄호"와 "닫는 괄호" 의 쌍이 안 맞는다면 false
//  2-2. 쌍이 맞다면, stack.pop()
// 3. 모든 탐색이 끝난 후, "Stack이 비어있어야만" 올바른 문자열이다.


#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

map<char, char> makeMap() {
    map<char, char> map;
    map['('] = ')';
    map['{'] = '}';
    map['['] = ']';
    return map;
}

bool isProper(string s, map<char, char> map) {
    stack<char> stack;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else {
            if (stack.empty() || map[stack.top()] != c) {
                return false;
            }
            stack.pop();
        }
    }

    if (stack.empty()) {
        return true;
    }

    return false;
}

string rotate(string s) {
    char c = s[0];
    s.erase(s.begin());
    s.push_back(c);
    return s;
}

int solution(string s) {
    int answer = 0;

    map<char, char> map = makeMap();

    for (int i = 0; i < s.length(); ++i) {
        bool flag = isProper(s, map);

        if (flag) {
            ++answer;
        }

        s = rotate(s);
    }

    return answer;
}