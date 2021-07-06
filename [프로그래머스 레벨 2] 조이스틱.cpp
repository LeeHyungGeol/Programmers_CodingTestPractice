// 그리디 문제

// left == i
// right == ind(i 다음에 있는 A가 아닌 문자)
// 1) (원점)0 -> i -> 0 -> ind : 2a + b
// 2) (원점)0 -> ind -> 0 -> i : a + 2b
// min(2a+b, a+2b) == a+b + min(a,b);
// a = i, b = n - ind
// -> step = min(step, i + n - ind + min(i, n - ind));

// https://unglog.tistory.com/8
// https://4z7l.github.io/2021/03/12/algorithms-prg-42860.html

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int step = n - 1;

    for (int i = 0; i < name.size(); ++i) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        int left = i;
        int right = i + 1;
        while (right < n && name[right] == 'A') {
            ++right;
        }

        step = min(step, left + n - right + min(left, n - right));
    }

    answer += step;

    return answer;
}