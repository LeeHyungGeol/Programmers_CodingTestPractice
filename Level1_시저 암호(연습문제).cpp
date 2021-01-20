#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    char ch;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            if (s[i] <= 90) {
                ch = ((s[i] - 'A') + n) % 26;
                answer += (ch + 'A');
            }
            else {
                ch = ((s[i] - 'a') + n) % 26;
                answer += (ch + 'a');
            }
        }
        else answer += " ";
    }
    return answer;
}
string solution2(string s, int n) {
    string answer = "";
    for (auto c : s) {
        if (c == ' ') {
            answer += c;
        }
        else if (c < 'a') {
            answer += static_cast<char>(((c - 'A') + n) % 26 + 'A');
        }
        else {
            answer += static_cast<char>(((c - 'a') + n) % 26 + 'a');
        }
    }
    return answer;
}
int main() {
    string text = "a B z";
    int testNo = 4;

    cout << solution(text, testNo) << '\n';
}