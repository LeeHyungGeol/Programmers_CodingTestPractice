// bfs, 방향전환count, Map(key를 기준으로 오름차순 자동정렬)

// 가중치가 없는 그래프에서의 최단 거리를 찾는 단순 bfs가 아닌,
// 방향 전환 count가 적다면, 그것을 우선적으로 처리하는 bfs가 필요하다.
// 따라서 동일한 위치더라도 더 적게 꺾어서 올 수 있다면 다시 재방문(큐에 또 삽입) 할 수 있어야 한다.
// 그 위치로부터 뻗어나가는 모든 위치들도 다시 새로운 방향전환 횟수로 업데이트 해야 한다.

// 그래서 방문여부만 따지는 visited배열을 이용한 bfs는 실패한다.

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
map<char, pii> Map;

pii bfs(int m, int n, vector<string> board, pii start);

string solution(int m, int n, vector<string> board) {
    string answer = "";

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].length(); ++j) {
            if (isalpha(board[i][j])) {
                Map[board[i][j]] = { i,j };
            }
        }
    }

    while (true) {
        bool flag = false;

        for (auto x : Map) {
            char alphabet = x.first;
            pii start = x.second;
            pii end = bfs(m, n, board, start);

            if (end.first != -1 && end.second != -1) {
                flag = true;
                board[start.first][start.second] = '.';
                board[end.first][end.second] = '.';
                answer += alphabet;
                Map.erase(alphabet);
                break;
            }
        }

        if (flag) {
            continue;
        }

        if (Map.empty()) {
            break;
        }
        else {
            answer = "IMPOSSIBLE";
            break;
        }
    }

    return answer;
}


pii bfs(int m, int n, vector<string> board, pii start) {
    queue<piiii> q;
    vector<vector<int>> turnCount(m, vector<int>(n, 3));
    pii result = { -1, -1 };

    q.push({ {-1,0}, {start.first, start.second} });
    turnCount[start.first][start.second] = 0;

    bool isFirst = true;

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int curD = q.front().first.first;
        int curTurn = q.front().first.second;
        q.pop();

        if (!isFirst && board[x][y] == board[start.first][start.second]) {
            result = { x,y };
            break;
        }

        isFirst = false;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextTurn = curTurn;

            if (curD != -1 && curD != i) {
                ++nextTurn;
            }

            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (board[nx][ny] == '.' || board[nx][ny] == board[start.first][start.second]) {
                    if (nextTurn < 2 && turnCount[nx][ny] >= nextTurn) {
                        turnCount[nx][ny] = nextTurn;
                        q.push({ {i, nextTurn}, {nx,ny} });
                    }
                }
            }
        }
    }

    return result;
}

//--------------------실패한 풀이--------------------------//

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
map<char, pii> Map;

pii bfs(int m, int n, vector<string> board, pii start);

string solution(int m, int n, vector<string> board) {
    string answer = "";

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].length(); ++j) {
            if (isalpha(board[i][j])) {
                Map[board[i][j]] = { i,j };
            }
        }
    }

    while (true) {
        bool flag = false;

        for (auto x : Map) {
            char alphabet = x.first;
            pii start = x.second;
            pii end = bfs(m, n, board, start);

            if (end.first != -1 && end.second != -1) {
                flag = true;
                board[start.first][start.second] = '.';
                board[end.first][end.second] = '.';
                answer += alphabet;
                Map.erase(alphabet);
                break;
            }
        }

        if (flag) {
            continue;
        }

        if (Map.empty()) {
            break;
        }
        else {
            answer = "IMPOSSIBLE";
            break;
        }
    }

    return answer;
}

pii bfs(int m, int n, vector<string> board, pii start) {
    queue<piiii> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    pii result = { -1, -1 };

    q.push({ {-1,0}, {start.first, start.second} });
    visited[start.first][start.second] = true;
    bool isFirst = true;

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int curD = q.front().first.first;
        int curTurn = q.front().first.second;
        q.pop();

        if (!isFirst && board[x][y] == board[start.first][start.second]) {
            result = { x,y };
            break;
        }

        isFirst = false;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextTurn = curTurn;

            if (curD != -1 && curD != i) {
                ++nextTurn;
            }

            if (0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny]) {
                if (board[nx][ny] == '.' || board[nx][ny] == board[start.first][start.second]) {
                    if (nextTurn < 2) {
                        visited[nx][ny] = true;
                        q.push({ {i, nextTurn}, {nx,ny} });
                    }
                }
            }
        }
    }

    return result;
}