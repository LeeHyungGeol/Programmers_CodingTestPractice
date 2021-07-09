// �ڷᱸ��, stack����
// �ùٸ� ��ȣ ���ڿ����� �ľ��ϴ� ����

// �ùٸ� ��ȣ���� �Ǵ��� �� ���� �߿��� ���� "���� �ֱٿ� ���� ���� ��ȣ" �̴�.
// Ž���� �Կ� �־ "���� �ֱٿ� ���� ���� ��ȣ" �� ���� ������ ����ؼ� ����

// 1. Stack�� ���ؼ� "���� ��ȣ"���� ������ ���̴�.
// 2. "�ݴ� ��ȣ"�� ������ �Ǹ�, Stack�� top()�� �ִ� "���� ��ȣ"�� �������� ��
//  2-1. stack�� ����ְų�, "���� ��ȣ"�� "�ݴ� ��ȣ" �� ���� �� �´´ٸ� false
//  2-2. ���� �´ٸ�, stack.pop()
// 3. ��� Ž���� ���� ��, "Stack�� ����־�߸�" �ùٸ� ���ڿ��̴�.

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool isProper(string s) {
    stack<char> stack;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '(') {
            stack.push(c);
        }
        else {
            if (stack.empty()) {
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

bool solution(string s) {
    bool answer = isProper(s);
    return answer;
}