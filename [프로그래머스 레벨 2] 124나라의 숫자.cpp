// 3진법으로 변환하는 방식은 동일하나 3으로 나누어 떨어지는 숫자는 몫을 -1해서 진행하는 방식
// 3진법은 012로 나타나지만 문제는 123(->4)로 표현하기때문에 3까지 하나의 자리에서 표현이 가능하다.
// 그렇기 때문에 기존에 진법 변환 방식으로 3진법 변환 도중에 현재 n이 3으로 나누어떨어지는 숫자인지만 예외처리한다.

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