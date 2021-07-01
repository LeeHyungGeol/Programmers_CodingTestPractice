// stack을 활용하는 문제!!!
// 한번에 생각해내지 못했다. 다음 번에는 자료구조들도 다시 한번 어떤 것을 사용할 수 있는지 생각해보자.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> stack;

    // 홀수일 경우 무조건 한개의 문자가 남는다.
    if (s.size() % 2 == 1) {
        return answer;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (stack.empty() || stack.top() != s[i]) {
            stack.push(s[i]);
        }
        else {
            stack.pop();
        }
    }

    if (stack.empty()) {
        answer = 1;
    }

    return answer;
}