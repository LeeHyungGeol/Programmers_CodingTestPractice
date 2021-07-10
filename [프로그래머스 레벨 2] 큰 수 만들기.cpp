// 그리디(탐욕법) 문제

// 처음에는 dfs를 이용한 조합 문제 => nCn-k 로 풀려고 하였으나, 
// n이 1자리 이상, 1,000,000자리 이하인 숫자여서 시간 초과가 난다.

// 결국에는 반복문을 돌면서 처음부터 n중에서 k만큼 찾아보면서 최댓값을 찾고,
// 또 그 다음 k만큼 돌면서 다음 k값을 찾도록 하게 하는 그 순간 순간 범위의 최댓값을 찾는 그리디 문제 였다.

// N의 범위가 1,000,000 이기 때문에, 시간복잡도를 O(N) 으로 해야, 시간 초과가 나지 않는다.

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