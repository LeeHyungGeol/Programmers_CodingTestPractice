//kmp알고리즘, 실패함수(getPartialMatch())를 사용해보려 했지만, 이 문제는 그걸 묻는게 아니었다.
//그냥 단순히 앞에서 부터 문자열을 1개, 2개, 3개씩 잘라가면서 비교해나가는 그런 문제였음.
//뻘 짓을 많이 해서 시간이 생각보다 오래 걸렸다.
//다음에 다 지우고 다시 풀어보자.
#include <string>
#include <vector>
#include <algorithm>    // std::min
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    //i는 자르는 문자의 개수
    for (int i = 1; i <= s.size() / 2; ++i) {
        string newString = "";
        string tmp = s.substr(0, i);
        int cnt = 1;
        //j는 문자열의 시작점
        for (int j = i; j < s.size(); j += i) {
            if (tmp == s.substr(j, i)) {
                cnt++;
            }
            else {
                if (cnt > 1) newString += to_string(cnt);
                newString += tmp;
                tmp = s.substr(j, i);
                cnt = 1;
            }
        }
        if (cnt > 1) newString += to_string(cnt);
        newString += tmp;
        //cout<<newString<<'\n';
        //int newStringSize=newString.size();
        //min함수 안에 (int)안넣어주면 틀림
        answer = min(answer, (int)newString.size());
    }
    return answer;
}
void print(string s, int answer) {
    int t = solution(s);
    if (answer == t)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}

int main() {
    print("a", 1);
    print("aaaaa", 2);
    print("aaaaaaaaaa", 3);
    print("aabbaccc", 7);
    print("ababcdcdababcdcd", 9);
    print("abcabcdede", 8);
    print("abcabcabcabcdededededede", 14);
    print("xababcdcdababcdcd", 17);
    return 0;
}