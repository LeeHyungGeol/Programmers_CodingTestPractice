#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//나의 풀이
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
//다른 사람의 풀이
string change124(int no)
{
    string answer = "";
    int a;
    while (no > 0) {
        a = no % 3;
        no = no / 3;
        if (a == 0) {
            no -= 1;
        }
        answer = "412"[a] + answer;
    }

    return answer;
}
int main()
{
    int testNo = 6;
    string testAnswer = solution(testNo);

    cout << testAnswer;
}