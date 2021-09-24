#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int isPalindrome(string s, int left, int right);

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.length(); ++i) {
        int even = isPalindrome(s, i - 1, i);
        int odd = isPalindrome(s, i, i);
        answer = max(answer, max(even, odd));
    }

    return answer;
}

int isPalindrome(string s, int left, int right) {
    while (0 <= left && right < s.length()) {
        if (s[left] != s[right]) {
            break;
        }
        --left;
        ++right;
    }
    return right - left - 1;
}