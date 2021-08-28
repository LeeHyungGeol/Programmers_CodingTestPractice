// dfs, 순열, 구현

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
char Arr[] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
vector<char> Cases;
vector<bool> Select;

void dfs(int cnt, vector<string> data);

int solution(int n, vector<string> data) {
    Answer = 0;
    Select.assign(8, false);
    Cases.assign(8, ' ');
    dfs(0, data);
    return Answer;
}

void dfs(int cnt, vector<string> data) {
    if (cnt == 8) {
        for (int i = 0; i < data.size(); ++i) {
            char a = data[i][0];
            char b = data[i][2];
            char cond = data[i][3];
            int diff = data[i][4] - '0';

            int aIndex = -1, bIndex = -1;

            for (int j = 0; j < Cases.size(); ++j) {
                if (Cases[j] == a) {
                    aIndex = j;
                }
                if (Cases[j] == b) {
                    bIndex = j;
                }
                if (aIndex != -1 && bIndex != -1) {
                    break;
                }
            }

            if (cond == '=' && abs(aIndex - bIndex) != diff + 1) {
                return;
            }
            if (cond == '>' && abs(aIndex - bIndex) <= diff + 1) {
                return;
            }
            if (cond == '<' && abs(aIndex - bIndex) >= diff + 1) {
                return;
            }
        }

        ++Answer;

        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (Select[i]) {
            continue;
        }
        Select[i] = true;
        Cases[cnt] = Arr[i];
        dfs(cnt + 1, data);
        Select[i] = false;
    }
}