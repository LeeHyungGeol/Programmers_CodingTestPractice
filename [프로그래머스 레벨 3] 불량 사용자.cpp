// dfs, ¼ø¿­(permutation), set

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<vector<int>> Candidates;
vector<bool> Select;
set<string> Set;
int userIdSize;

void dfs(int cnt, int N);

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    userIdSize = user_id.size();
    Candidates.resize(banned_id.size());
    Select.resize(user_id.size(), false);

    for (int i = 0; i < banned_id.size(); ++i) {
        for (int j = 0; j < user_id.size(); ++j) {
            if (banned_id[i].length() != user_id[j].length()) {
                continue;
            }
            bool flag = true;
            for (int k = 0; k < user_id[j].size(); ++k) {
                if (banned_id[i][k] == '*') {
                    continue;
                }
                if (banned_id[i][k] != user_id[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                Candidates[i].push_back(j);
            }
        }
    }

    dfs(0, banned_id.size());

    return (int)Set.size();
}

void dfs(int cnt, int N) {
    if (cnt == N) {
        string temp = "";
        for (int i = 0; i < userIdSize; ++i) {
            if (Select[i]) {
                temp += to_string(i);
            }
        }
        Set.insert(temp);
        return;
    }

    for (int i = 0; i < Candidates[cnt].size(); ++i) {
        int cur = Candidates[cnt][i];
        if (Select[cur]) {
            continue;
        }
        Select[cur] = true;
        dfs(cnt + 1, N);
        Select[cur] = false;
    }
}