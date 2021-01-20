#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    for (int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";//bit연산//홀수는 항상 1자리의 bit값이 1임을 이용

    return answer;
}
string solution2(int n) {
    string answer = "";
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) answer += "수";
        else if (i % 2 == 0) answer += "박";
    }
    return answer;
}