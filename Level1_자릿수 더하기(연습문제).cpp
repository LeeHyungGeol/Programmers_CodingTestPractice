//�ڿ��� N�� �־�����, N�� �� �ڸ����� ���� ���ؼ� return �ϴ� solution �Լ��� ����� �ּ���.
//������� N = 123�̸� 1 + 2 + 3 = 6�� return �ϸ� �˴ϴ�.
//N�� ���� : 100,000,000 ������ �ڿ���
#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n) {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}
int solution2(int n)
{
    int answer = 0;

    string s = to_string(n);

    for (int i = 0; i < s.size(); i++) answer += (s[i] - '0');

    return answer;
}