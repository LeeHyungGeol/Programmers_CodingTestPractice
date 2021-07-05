#include <iostream>

using namespace std;

int getRank(int num);

int solution(int n, int a, int b) {
    int answer = 0;

    while (true) {
        if ((a % 2 == 0 && a - 1 == b) || (a % 2 != 0 && a + 1 == b)) {
            break;
        }

        a = getRank(a);
        b = getRank(b);

        ++answer;
    }

    ++answer;

    return answer;
}

int getRank(int num) {
    if (num % 2 == 0) {
        num /= 2;
    }
    else {
        num = num / 2 + 1;
    }
    return num;
}