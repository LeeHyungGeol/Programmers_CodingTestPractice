// dfs/bfs 문제
// 전형적인 Connected Components 문제이다. 
// 거기에 각각의 components들의 nodes의 개수를 구하여 그 값들의 최댓값을 구하는 문제.

#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<vector<bool>> Visited;

vector<int> dfsAll(int m, int n, vector<vector<int>> picture);
int dfs(int x, int y, int m, int n, vector<vector<int>> picture, int curColor);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer = dfsAll(m, n, picture);
    return answer;
}

vector<int> dfsAll(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0, max_size_of_one_area = 0;
    vector<int> result;

    Visited.assign(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!Visited[i][j] && picture[i][j] != 0) {
                int nodes = dfs(i, j, m, n, picture, picture[i][j]);
                ++number_of_area;
                max_size_of_one_area = max(max_size_of_one_area, nodes);
            }
        }
    }

    result.push_back(number_of_area);
    result.push_back(max_size_of_one_area);

    return result;
}

int dfs(int x, int y, int m, int n, vector<vector<int>> picture, int curColor) {
    int nodes = 1;
    Visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (!Visited[nx][ny] && picture[nx][ny] == curColor) {
                nodes += dfs(nx, ny, m, n, picture, picture[nx][ny]);
            }
        }
    }

    return nodes;
}