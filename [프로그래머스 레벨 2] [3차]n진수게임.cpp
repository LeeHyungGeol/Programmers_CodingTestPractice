// n������ ���ϴ� ����

// n������ ���� ��, number�迭�� �̿��ϸ� ���ϴ�.

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


//-----------------���� Ǯ��-------------------//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numlist = "";
    //�̸� ���� ���ڿ��� ������ ���ڰ� t(�̸� ���� ������ ���� ) * m(���ӿ� �����ϴ� �ο�)�̶�� 
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
        //6�� ��� 2�����϶�, 110�ε�, 011�� ������ �����Ƿ� �̰��� reverse()�Լ��� ������ �ش�.
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