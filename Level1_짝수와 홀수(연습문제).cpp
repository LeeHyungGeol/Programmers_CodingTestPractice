//���� num�� ¦���� ��� Even�� ��ȯ�ϰ� Ȧ���� ��� Odd�� ��ȯ�ϴ� �Լ�, solution�� �ϼ����ּ���.
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return (num & 1) ? "Odd" : "Even";
}
string solution2(int num) {
    return (num % 2) ? "Odd" : "Even";
}