// dp����
// (���� ��� 4) ��������(1520��) �� �ſ� ������ ������.

#include <vector>
#include <cstring>

using namespace std;

int MOD = 20170805;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int dp[501][501][2];

int dfs(int x, int y, int z, int m, int n, vector<vector<int>>& city_map);

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, -1, sizeof(dp));
    int answer = dfs(0, 0, 0, m, n, city_map);
    return answer;
}

int dfs(int x, int y, int z, int m, int n, vector<vector<int>>& city_map) {
    if (x == m - 1 && y == n - 1) {
        return 1;
    }
    if (dp[x][y][z] != -1) {
        return dp[x][y][z];
    }

    dp[x][y][z] = 0;

    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < m && 0 <= ny && ny < n) {
            if (city_map[x][y] == 0 || (city_map[x][y] == 2 && z == i)) {
                dp[x][y][z] += dfs(nx, ny, i, m, n, city_map) % MOD;
            }
        }
    }

    return dp[x][y][z] % MOD;
}

