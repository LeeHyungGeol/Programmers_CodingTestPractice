// 2칸이 함께 이동하는 Node의 bfs

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
    int x1, y1, x2, y2;
}Node;
typedef pair<Node, int> pni;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int hor[] = { -1,1 };
int ver[] = { -1,1 };
vector<vector<Node>> Board;

vector<Node> getNextPossiblePositions(Node cur, vector<vector<int>>& board);

int solution(vector<vector<int>> board) {
    int answer = 0;

    vector<vector<int>> Board(board.size() + 2, vector<int>(board.size() + 2, 1));

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            Board[1 + i][1 + j] = board[i][j];
        }
    }

    queue<pni> q;
    vector<Node> visited;
    Node start = { 1,1,1,2 };

    q.push({ start,0 });
    visited.push_back(start);

    while (!q.empty()) {
        Node cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        if ((cur.x1 == board.size() && cur.y1 == board.size()) || (cur.x2 == board.size() && cur.y2 == board.size())) {
            answer = cost;
            break;
        }

        vector<Node> nextPossiblePositions = getNextPossiblePositions(cur, Board);

        for (int i = 0; i < nextPossiblePositions.size(); ++i) {
            bool flag = true;
            Node next = nextPossiblePositions[i];

            for (int j = 0; j < visited.size(); ++j) {
                if (next.x1 == visited[j].x1 && next.y1 == visited[j].y1 && next.x2 == visited[j].x2 && next.y2 == visited[j].y2) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                visited.push_back(next);
                q.push({ next, cost + 1 });
            }
        }
    }

    return answer;
}

vector<Node> getNextPossiblePositions(Node cur, vector<vector<int>>& board) {
    vector<Node> nextPossiblePositions;

    for (int i = 0; i < 4; ++i) {
        int nx1 = cur.x1 + dx[i];
        int ny1 = cur.y1 + dy[i];
        int nx2 = cur.x2 + dx[i];
        int ny2 = cur.y2 + dy[i];

        if (board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
            nextPossiblePositions.push_back({ nx1,ny1,nx2,ny2 });
        }
    }

    if (cur.x1 == cur.x2) {
        for (int i = 0; i < 2; ++i) {
            int nx1 = cur.x1 + hor[i];
            int nx2 = cur.x2 + hor[i];

            if (board[nx1][cur.y1] == 0 && board[nx2][cur.y2] == 0) {
                nextPossiblePositions.push_back({ cur.x1,cur.y1,nx1,cur.y1 });
                nextPossiblePositions.push_back({ cur.x2,cur.y2,nx2,cur.y2 });

            }
        }
    }

    if (cur.y1 == cur.y2) {
        for (int i = 0; i < 2; ++i) {
            int ny1 = cur.y1 + ver[i];
            int ny2 = cur.y2 + ver[i];

            if (board[cur.x1][ny1] == 0 && board[cur.x2][ny2] == 0) {
                nextPossiblePositions.push_back({ cur.x1, cur.y1, cur.x1, ny1 });
                nextPossiblePositions.push_back({ cur.x2, cur.y2, cur.x2, ny2 });

            }
        }
    }

    return nextPossiblePositions;
}