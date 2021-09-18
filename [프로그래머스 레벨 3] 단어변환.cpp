// dfs, bfs 모두 가능한 문제

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

int Answer = INF;
vector<bool> Visited;

void dfs(string begin, string target, vector<string>& words, int count);

int solution(string begin, string target, vector<string> words) {
    Visited.resize(words.size(), false);

    dfs(begin, target, words, 0);

    if (Answer == INF) {
        Answer = 0;
    }

    return Answer;
}

void dfs(string begin, string target, vector<string>& words, int count) {
    if (begin == target) {
        Answer = min(Answer, count);
        return;
    }

    for (int i = 0; i < words.size(); ++i) {
        int cnt = 0;
        for (int j = 0; j < words[i].length(); ++j) {
            if (begin[j] != words[i][j]) {
                ++cnt;
            }
        }

        if (cnt == 1 && !Visited[i]) {
            Visited[i] = true;
            dfs(words[i], target, words, count + 1);
            Visited[i] = false;
        }
    }
}

//-----------------bfs풀이-------------------//

typedef pair<string, int> psi;

int solution2(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size(), false);
    queue<psi> q;

    q.push({ begin, 0 });

    while (!q.empty()) {
        string cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if (cur == target) {
            answer = count;
            break;
        }

        for (int i = 0; i < words.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < words[i].length(); ++j) {
                if (cur[j] != words[i][j]) {
                    ++cnt;
                }
            }

            if (cnt == 1 && !visited[i]) {
                visited[i] = true;
                q.push({ words[i], count + 1 });
            }
        }
    }

    return answer;
}