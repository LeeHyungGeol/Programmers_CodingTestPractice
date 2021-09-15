#include <string>
#include <vector>

using namespace std;

int dfs(int cur, vector<vector<int>>& computers, vector<bool>& visited);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int nodes = dfs(i, computers, visited);
            ++answer;
        }
    }

    return answer;
}

int dfs(int cur, vector<vector<int>>& computers, vector<bool>& visited) {
    int nodes = 1;
    visited[cur] = true;

    for (int i = 0; i < computers[cur].size(); ++i) {
        int next = computers[cur][i];
        if (!visited[i] && next == 1) {
            nodes += dfs(i, computers, visited);
        }
    }

    return nodes;
}