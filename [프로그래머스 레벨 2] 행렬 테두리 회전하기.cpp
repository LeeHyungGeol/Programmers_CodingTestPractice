#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 동, 남, 서, 북
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int X1, X2, Y1, Y2;

int turn(int x, int y, int direction);
vector<int> solution(int rows, int columns, vector<vector<int>> queries);

int main() {
    vector<vector<int>> queries = { {2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3} };
    vector<int> answers = solution(6, 6, queries);

    for (auto answer : answers) {
        cout << answer << '\n';
    }

    return 0;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows, vector<int>(columns));
    int tmp = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            arr[i][j] = ++tmp;
        }
    }

    for (auto q : queries) {
        X1 = q[0] - 1;
        Y1 = q[1] - 1;
        X2 = q[2] - 1;
        Y2 = q[3] - 1;

        int x = X1;
        int y = Y1;

        // 처음 방향은 무조건 동쪽 방향
        int direction = 0;
        // 최솟값
        int Min = 987654321;
        int swapTmp = arr[x][y];

        Min = min(Min, arr[x][y]);

        while (true) {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            Min = min(Min, arr[nx][ny]);

            int temp = arr[nx][ny];
            swap(swapTmp, arr[nx][ny]);
            swapTmp = temp;

            x = nx;
            y = ny;

            direction = turn(x, y, direction);

            if (x == X1 && y == Y1) {
                break;
            }
        }
        answer.push_back(Min);
    }

    return answer;
}

int turn(int x, int y, int direction) {
    if (x == X1 && y == Y2) {
        direction = 1;
    }
    else if (x == X2 && y == Y2) {
        direction = 2;
    }
    else if (x == X2 && y == Y1) {
        direction = 3;
    }
    return direction;
}