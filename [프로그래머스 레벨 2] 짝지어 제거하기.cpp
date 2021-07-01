// stack�� Ȱ���ϴ� ����!!!
// �ѹ��� �����س��� ���ߴ�. ���� ������ �ڷᱸ���鵵 �ٽ� �ѹ� � ���� ����� �� �ִ��� �����غ���.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> stack;

    // Ȧ���� ��� ������ �Ѱ��� ���ڰ� ���´�.
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