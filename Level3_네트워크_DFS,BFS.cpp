#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visited;

int dfs(vector<vector<int>>& graph, int cur) {
    int nodes = 1;
    visited[cur] = true;
    for (int i = 0; i < graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if (!visited[i] && next == 1) {
            nodes += dfs(graph, i);
        }
    }
    return nodes;
}

int getComponents(vector<vector<int>>& graph, int N) {
    int components = 0;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int nodes = dfs(graph, i);
            cout << "components size : " << nodes << '\n';
            components++;
        }
    }
    return components;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.resize(n, false);

    answer = getComponents(computers, n);

    return answer;
}