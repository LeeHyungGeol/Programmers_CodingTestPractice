//�ڿ��� n�� ������ �� �ڸ� ���ڸ� ���ҷ� ������ �迭 ���·� �������ּ���.
//������� n�� 12345�̸� [5,4,3,2,1]�� �����մϴ�.
//n�� 10,000,000,000������ �ڿ����Դϴ�.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i)
        answer.push_back(s[i] - '0');
    return answer;
}
vector<int> solution2(long long n) {
    vector<int> answer;
    while (n) {
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}