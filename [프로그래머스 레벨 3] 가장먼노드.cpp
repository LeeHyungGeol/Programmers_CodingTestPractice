#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int bfs(int n, vector<vector<int>>& graph);

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);

    for (vector<int> e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    int answer = bfs(n, graph);

    return answer;
}

int bfs(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, -1);
    queue<int> q;
    int MAX = -INF;

    q.push(1);
    dist[1] = 0;
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (!visited[next]) {
                dist[next] = dist[cur] + 1;
                visited[next] = true;
                MAX = max(MAX, dist[next]);
                q.push(next);
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == MAX) {
            ++cnt;
        }
    }

    return cnt;
}