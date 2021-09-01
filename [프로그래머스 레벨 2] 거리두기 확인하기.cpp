// bfs, 완전탐색, 구현

#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool isDistance(vector<string> place);
bool check(vector<string> place, int x, int y);

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (vector<string> place : places) {
        if (isDistance(place)) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}

bool isDistance(vector<string> place) {
    for (int i = 0; i < place.size(); ++i) {
        for (int j = 0; j < place[i].size(); ++j) {
            if (place[i][j] == 'P' && !check(place, i, j)) {
                return false;
            }
        }
    }

    return true;
}

bool check(vector<string> place, int x, int y) {
    queue<piii> q;
    vector<vector<bool>> visited(5, vector<bool>(5, false));

    q.push({ 0,{x,y} });
    visited[x][y] = true;

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dist = q.front().first;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && dist + 1 <= 2 && !visited[nx][ny]) {
                if (place[nx][ny] == 'O') {
                    visited[nx][ny] = true;
                    q.push({ dist + 1,{nx,ny} });
                }
                else if (place[nx][ny] == 'P') {
                    return false;
                }
            }
        }
    }

    return true;
}