#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n; i++)
        i & 1 ? answer += "��" : answer += "��";//bit����//Ȧ���� �׻� 1�ڸ��� bit���� 1���� �̿�

    return answer;
}
string solution2(int n) {
    string answer = "";
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) answer += "��";
        else if (i % 2 == 0) answer += "��";
    }
    return answer;
}