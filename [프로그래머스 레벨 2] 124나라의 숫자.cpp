// 3�������� ��ȯ�ϴ� ����� �����ϳ� 3���� ������ �������� ���ڴ� ���� -1�ؼ� �����ϴ� ���
// 3������ 012�� ��Ÿ������ ������ 123(->4)�� ǥ���ϱ⶧���� 3���� �ϳ��� �ڸ����� ǥ���� �����ϴ�.
// �׷��� ������ ������ ���� ��ȯ ������� 3���� ��ȯ ���߿� ���� n�� 3���� ����������� ���������� ����ó���Ѵ�.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    while (n) {
        int tmp = n % 3;
        if (tmp == 0) { answer += "4"; n /= 3; n -= 1; continue; }
        if (tmp == 1) answer += "1";
        if (tmp == 2) answer += "2";
        n /= 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

string solution2(int n) {
    string answer = "";

    while (n > 3) {
        int temp = n % 3;
        if (temp == 0) {
            answer += "4";
            n = n / 3 - 1;
        }
        else {
            answer += to_string(n % 3);
            n /= 3;
        }
    }

    if (n == 3) {
        answer += "4";
    }
    else {
        answer += to_string(n);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    int testNo = 6;
    string testAnswer = solution(testNo);

    cout << testAnswer;
}