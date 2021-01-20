//������ ���� ���� n�� ����, n�� � ���� ���� x�� �������� �ƴ��� �Ǵ��Ϸ� �մϴ�.
//n�� ���� ���� x�� �����̶�� x + 1�� ������ �����ϰ�, 
//n�� ���� ���� x�� ������ �ƴ϶�� - 1�� �����ϴ� �Լ��� �ϼ��ϼ���.
//n�� 1�̻�, 50000000000000 ������ ���� �����Դϴ�.
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double ipart;
    if (modf(sqrt(n), &ipart)) answer = -1;
    else {
        answer = pow(sqrt(n) + 1, 2);
    }
    return answer;
}
long long solution2(long long n) {
    return powl(sqrt(n), 2) == n ? powl(sqrt(n) + 1, 2) : -1;
}