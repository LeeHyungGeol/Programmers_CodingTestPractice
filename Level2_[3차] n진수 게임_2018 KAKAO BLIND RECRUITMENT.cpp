//n������ ���ϴ� ����
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