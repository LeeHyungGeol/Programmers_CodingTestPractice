#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> Graph;
vector<int> Dist;

vector<int> bfs(int start, int n);

int solution(int n, vector<vector<int>> edge) {
    Graph.resize(n + 1);
    Dist.resize(n + 1, -1);

    for (vector<int> e : edge) {
        Graph[e[0]].push_back(e[1]);
        Graph[e[1]].push_back(e[0]);
    }

    vector<int> answer = bfs(1, n);

    return answer.size();
}

vector<int> bfs(int start, int n) {
    vector<int> result;
    queue<int> q;
    int Max = -1;

    q.push(start);
    Dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : Graph[cur]) {
            if (Dist[next] != -1) continue;
            Dist[next] = Dist[cur] + 1;
            Max = max(Max, Dist[next]);
            q.push(next);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (Dist[i] == Max) result.push_back(i);
    }

    return result;
}