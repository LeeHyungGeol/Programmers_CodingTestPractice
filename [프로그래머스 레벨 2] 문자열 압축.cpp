// 구현 문제
// 요구하는데로 충실히 구현하면 된다. 
// 입력으로 주어지는 문자열의 길이가 1000 이하이기 때문에, 
// 가능한 모든 경우의 수를 완전 탐색하면 된다.

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