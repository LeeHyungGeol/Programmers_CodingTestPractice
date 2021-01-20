//자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요.
//예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
//n은 10,000,000,000이하인 자연수입니다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i)
        answer.push_back(s[i] - '0');
    return answer;
}
vector<int> solution2(long long n) {
    vector<int> answer;
    while (n) {
        answer.push_back(n % 10);
        n /= 10;
    }
    return answer;
}