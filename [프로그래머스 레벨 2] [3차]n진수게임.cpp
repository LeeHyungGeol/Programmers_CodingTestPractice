// n진법을 구하는 문제

// n진수를 구할 때, number배열을 이용하면 편하다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Numbers = { "0","1","2","3","4","5","6","7","8","9", "A", "B", "C", "D", "E", "F" };

string changeNum(int num, int n) {
    string temp = "";

    if (num == 0) {
        temp += Numbers[num];
        return temp;
    }

    while (num) {
        temp += Numbers[num % n];
        num /= n;

    }

    reverse(temp.begin(), temp.end());

    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numList = "";

    for (int i = 0; i <= m * t; ++i) {
        string num = changeNum(i, n);
        numList += num;
    }

    for (int i = p; i <= numList.size(); i += m, --t) {
        if (t == 0) {
            break;
        }
        answer += numList[i - 1];
    }

    return answer;
}


//-----------------예전 풀이-------------------//

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