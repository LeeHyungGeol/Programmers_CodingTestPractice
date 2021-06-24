// 구현 문제
// 요구하는데로 충실히 구현하면 된다. 
// 입력으로 주어지는 문자열의 길이가 1000 이하이기 때문에, 
// 가능한 모든 경우의 수를 완전 탐색하면 된다.

// 입력으로 길이가 N인 문자열이 들어왔을 때,
// 1 부터 N/2 까지를 단위로 하여 문자열을 압축하는 방법을 확인하고,
// 가장 짧게 압축되는 문자열의 길이를 출력하면 된다.

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