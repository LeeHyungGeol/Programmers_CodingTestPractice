// dp ����
// (���� ��� 4) ��������(1520��)
// (���α׷��ӽ� ���� 3) ������ õ��(2017 īī�� �ڵ� ����)
// ���� ������� �Ȱ��� ����

#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
vector<vector<int>> Graph;
vector<vector<int>> Dp;

int dfs(int m, int n, int x, int y);

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    Graph.resize(m, vector<int>(n, 0));
    Dp.resize(m, vector<int>(n, -1));

    for (vector<int> p : puddles) {
        Graph[p[0] - 1][p[1] - 1] = 1;
    }

    answer = dfs(m, n, 0, 0);

    return answer;
}

int dfs(int m, int n, int x, int y) {
    if (x == m - 1 && y == n - 1) {
        return 1;
    }
    if (Dp[x][y] != -1) {
        return Dp[x][y];
    }

    Dp[x][y] = 0;

    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (Graph[nx][ny] == 0) {
                Dp[x][y] += dfs(m, n, nx, ny) % MOD;
            }
        }
    }

    return Dp[x][y] % MOD;
}