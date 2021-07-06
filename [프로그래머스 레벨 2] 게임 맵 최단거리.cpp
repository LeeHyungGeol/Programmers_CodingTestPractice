// dfs/bfs 문제
// 전형적인 bfs 최단거리 문제
// 간선의 비용이 모두 일정할 때, bfs를 이용하면 최단거리를 구할 수 있다.

#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visited[100][100];

int bfs(int x, int y, vector<vector<int>> maps);

int solution(vector<vector<int>> maps) {
    int answer = 0;

    answer = bfs(0, 0, maps);

    return answer;
}

int bfs(int x, int y, vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> d(n, vector<int>(m, 1));
    queue<pii> q;

    q.push({ x,y });
    visited[x][y] = true;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!visited[nx][ny] && maps[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    d[nx][ny] = d[curX][curY] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }

    if (d[n - 1][m - 1] == 1) {
        return -1;
    }
    else {
        return d[n - 1][m - 1];
    }
}