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