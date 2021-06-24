// ���� ����
// �䱸�ϴµ��� ����� �����ϸ� �ȴ�. 
// �Է����� �־����� ���ڿ��� ���̰� 1000 �����̱� ������, 
// ������ ��� ����� ���� ���� Ž���ϸ� �ȴ�.

// �Է����� ���̰� N�� ���ڿ��� ������ ��,
// 1 ���� N/2 ������ ������ �Ͽ� ���ڿ��� �����ϴ� ����� Ȯ���ϰ�,
// ���� ª�� ����Ǵ� ���ڿ��� ���̸� ����ϸ� �ȴ�.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();

    for (int unit = 1; unit < (s.size() / 2) + 1; ++unit) {
        string result = "";
        string prev = s.substr(0, unit);
        int cnt = 1;

        for (int j = unit; j < s.size(); j += unit) {
            if (prev == s.substr(j, unit)) {
                ++cnt;
            }
            else {
                result += (cnt >= 2) ? to_string(cnt) + prev : prev;
                prev = s.substr(j, unit);
                cnt = 1;
            }
        }
        result += (cnt >= 2) ? to_string(cnt) + prev : prev;
        answer = min(answer, (int)result.size());
    }

    return answer;
}

int main() {
    string str = "abcabcabcabcdededededede";
    cout << solution(str) << '\n';
    return 0;
}