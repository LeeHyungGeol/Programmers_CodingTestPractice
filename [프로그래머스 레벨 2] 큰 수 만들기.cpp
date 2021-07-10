// �׸���(Ž���) ����

// ó������ dfs�� �̿��� ���� ���� => nCn-k �� Ǯ���� �Ͽ�����, 
// n�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ ���ڿ��� �ð� �ʰ��� ����.

// �ᱹ���� �ݺ����� ���鼭 ó������ n�߿��� k��ŭ ã�ƺ��鼭 �ִ��� ã��,
// �� �� ���� k��ŭ ���鼭 ���� k���� ã���� �ϰ� �ϴ� �� ���� ���� ������ �ִ��� ã�� �׸��� ���� ����.

// N�� ������ 1,000,000 �̱� ������, �ð����⵵�� O(N) ���� �ؾ�, �ð� �ʰ��� ���� �ʴ´�.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 1e9
using namespace std;

vector<bool> Select;
long long Max = -MAX;

string solution(string number, int k) {
    string answer = "";
    int start = 0, maxIndex = 0;
    char maxNum = NULL;

    for (int i = 0; i < number.size() - k; ++i) {
        maxNum = number[start];
        maxIndex = start;

        for (int j = start; j <= i + k; ++j) {
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIndex = j;
            }
        }

        start = maxIndex + 1;
        answer += maxNum;
    }

    return answer;
}


void dfs(const string& number, int startIndex, int cnt, int k) {
    if (cnt == number.size() - k) {
        string temp = "";
        for (int i = 0; i < number.size(); ++i) {
            if (Select[i]) {
                temp += to_string(number[i] - '0');
            }
        }
        Max = max(Max, stoll(temp));
        return;
    }

    for (int i = startIndex; i < number.size(); ++i) {
        if (Select[i]) {
            continue;
        }
        Select[i] = true;
        dfs(number, i, cnt + 1, k);
        Select[i] = false;
    }
}

string solution2(string number, int k) {
    string answer = "";
    int N = number.size();
    Select.resize(N);

    dfs(number, 0, 0, k);

    answer = to_string(Max);
    return answer;
}

int main() {
    cout << solution("4177252841", 4) << '\n';

    return 0;
}