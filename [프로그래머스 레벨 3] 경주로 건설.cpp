// bfs, 방향전환

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2e9

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs(vector<vector<int>>& board, int dir);

int solution(vector<vector<int>> board) {
    int result1 = bfs(board, 1);
    int result2 = bfs(board, 3);
    int answer = min(result1, result2);
    return answer;
}

int bfs(vector<vector<int>>& board, int dir) {
    queue<piiii> q;
    vector<vector<int>> dist(board.size(), vector<int>(board.size(), INF));
    int result = INF;

    dist[0][0] = 0;

    if (dir == 3 && board[0][1] == 0) {
        q.push({ {3, 100},{0,1} });
        dist[0][1] = 100;
    }
    if (dir == 1 && board[1][0] == 0) {
        q.push({ {1, 100},{1,0 } });
        dist[1][0] = 100;
    }

    while (!q.empty()) {
        int curD = q.front().first.first;
        int cost = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == board.size() - 1 && y == board.size() - 1) {
            result = min(result, dist[x][y]);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board.size()) {
                if (board[nx][ny] != 1) {
                    int nCost = 0;
                    if (curD != -1 && curD != i) {
                        nCost = cost + 600;
                    }
                    else {
                        nCost = cost + 100;
                    }
                    if (dist[nx][ny] >= nCost) {
                        dist[nx][ny] = nCost;
                        q.push({ {i,nCost},{nx,ny} });
                    }
                }
            }
        }
    }

    return result;
}