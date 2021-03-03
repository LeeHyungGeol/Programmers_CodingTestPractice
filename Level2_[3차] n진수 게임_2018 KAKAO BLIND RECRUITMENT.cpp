//n진법을 구하는 문제
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numlist = "";
    //미리 구할 문자열의 마지막 숫자가 t(미리 구할 숫자의 갯수 ) * m(게임에 참가하는 인원)이라는 
    for (int i = 0; i <= t * m; ++i) {
        string tmp = "";
        int N = i;
        if (N == 0) { numlist += "0"; continue; }
        while (N) {
            int num = N % n;
            if (num >= 10) tmp += 'A' + (num % 10);
            else tmp += to_string(num);
            N /= n;
        }
        //6의 경우 2진법일때, 110인데, 011의 값으로 나오므로 이것을 reverse()함수로 뒤집어 준다.
        reverse(tmp.begin(), tmp.end());
        numlist += tmp;
    }

    for (int i = p; i <= numlist.size(); i += m) {
        if (!t) break;
        answer += numlist[i - 1];
        t--;
    }
    return answer;
}
int main() {
    int n = 16, t = 16, m = 2, p = 2;
    cout << "answer : " << solution(n, t, m, p) << '\n';

    return 0;
}