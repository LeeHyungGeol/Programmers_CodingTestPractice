#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool Select[8];
char arr[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
char cases[8];

// 순열 문제
void dfs(int cnt, vector<string> data) {
    if (cnt == 8) {
        for (int i = 0; i < data.size(); ++i) {
            char x1 = data[i][0];
            char x2 = data[i][2];
            char condition = data[i][3];
            int dist = data[i][4] - '0';

            int x1Index = -1, x2Index = -1;

            for (int j = 0; j < 8; ++j) {
                if (cases[j] == x1) {
                    x1Index = j;
                }
                if (cases[j] == x2) {
                    x2Index = j;
                }
                if (x1Index != -1 && x2Index != -1) {
                    break;
                }
            }

            // 같음
            if (condition == '=' && abs(x1Index - x2Index) != dist + 1) {
                return;
            }
            // 초과
            if (condition == '<' && abs(x1Index - x2Index) >= dist + 1) {
                return;
            }
            // 미만
            if (condition == '>' && abs(x1Index - x2Index) <= dist + 1) {
                return;
            }
        }

        ++answer;

        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (Select[i]) {
            continue;
        }
        Select[i] = true;
        cases[cnt] = arr[i];
        dfs(cnt + 1, data);
        Select[i] = false;
    }
}

int solution(int n, vector<string> data) {
    answer = 0;

    dfs(0, data);

    return answer;
}