// ���� ����
// �䱸�ϴµ��� ����� �����ϸ� �ȴ�. 
// �Է����� �־����� ���ڿ��� ���̰� 1000 �����̱� ������, 
// ������ ��� ����� ���� ���� Ž���ϸ� �ȴ�.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int length = s.length();

    for (int step = 1; step <= length / 2; ++step) {
        string temp = "";
        string compare = s.substr(0, step);
        int cnt = 0;

        for (int i = 0; i < length; i += step) {
            string cur = s.substr(i, step);

            if (cur == compare) {
                ++cnt;
            }
            else {
                if (cnt >= 2) {
                    temp += to_string(cnt) + compare;
                }
                else {
                    temp += compare;
                }
                compare = cur;
                cnt = 1;
            }
        }

        if (cnt >= 2) {
            temp += to_string(cnt) + compare;
        }
        else {
            temp += compare;
        }

        answer = min(answer, (int)temp.length());
    }

    return answer;
}

int main() {
    string str = "abcabcabcabcdededededede";
    cout << solution(str) << '\n';
    return 0;
}