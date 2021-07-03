// dfs/bfs 문제
// 전형적인 Connected Components 문제이다. 
// 거기에 각각의 components들의 nodes의 개수를 구하여 그 값들의 최댓값을 구하는 문제.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

bool visited[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

pii dfsAll(int m, int n, vector<vector<int>> picture);
int dfs(int x, int y, int curColor, vector<vector<int>> picture);

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    pii answers = dfsAll(m, n, picture);

    int number_of_area = answers.first;
    int max_size_of_one_area = answers.second;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


pii dfsAll(int m, int n, vector<vector<int>> picture) {
    int components = 0;
    int maxConnectedNodes = 0;

    for (int i = 0; i < 100; ++i) {
        fill(visited[i], visited[i] + 100, false);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && picture[i][j] > 0) {
                int nodes = dfs(i, j, picture[i][j], picture);
                ++components;
                maxConnectedNodes = max(maxConnectedNodes, nodes);
            }
        }
    }

    return { components, maxConnectedNodes };
}

int dfs(int x, int y, int curColor, vector<vector<int>> picture) {
    visited[x][y] = true;

    int nodes = 1;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < picture.size() && 0 <= ny && ny < picture[0].size()) {
            if (!visited[nx][ny] && curColor == picture[nx][ny]) {
                nodes += dfs(nx, ny, curColor, picture);
            }
        }
    }

    return nodes;
}