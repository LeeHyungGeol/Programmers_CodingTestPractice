#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

int answer = 0;

void dfs(string& begin, string& target, vector<string>& words, int result) {
    if (begin == target) {
        answer = result;
        return;
    }

    for (int i = 0; i < words.size(); ++i) {
        int count = 0;
        for (int j = 0; j < words[i].size(); ++j) {
            if (begin[j] != words[i][j]) {
                count++;
            }
        }
        if (count == 1 && visited[i] == false) {
            visited[i] = true;
            dfs(words[i], target, words, result + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    visited.resize(words.size(), false);

    dfs(begin, target, words, 0);

    if (answer == 100) {
        return answer = 0;
    }

    return answer;
}

int solution2(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;

    q.push({ begin, 0 });

    while (!q.empty()) {
        string start = q.front().first;
        int result = q.front().second;

        q.pop();

        for (int i = 0; i < words.size(); ++i) {
            int count = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                if (start[j] != words[i][j]) {
                    count++;
                }
            }
            if (count == 1 && visited[i] == false) {
                if (words[i] == target) {
                    answer = result + 1;
                }
                visited[i] = true;
                q.push({ words[i], result + 1 });
            }
        }
    }

    return answer;
}