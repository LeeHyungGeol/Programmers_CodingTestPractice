// graph������ ���� : ��������, �÷��̵����, dfs(Tree�϶�) 

// �� ������ (���� ��� 4) Ű ����(2458��)�� �Ȱ��� �����̴�.
// �÷��̵���� �˰������� '��� ��忡�� �ٸ� ��� ��� ������ `����`'�� �� �� �ִ�.

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (vector<int> result : results) {
        graph[result[0]][result[1]] = 1;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            if (graph[i][j] || graph[j][i]) {
                ++cnt;
            }
        }
        if (cnt == n - 1) {
            ++answer;
        }
    }

    return answer;
}