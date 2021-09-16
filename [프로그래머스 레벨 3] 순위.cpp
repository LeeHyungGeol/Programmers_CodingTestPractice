// graph에서의 순위 : 위상정렬, 플로이드워셜, dfs(Tree일때) 

// 이 문제는 (백준 골드 4) 키 순서(2458번)과 똑같은 문제이다.
// 플로이드워셜 알고리즘으로 '모든 노드에서 다른 모든 노드 사이의 `관계`'를 알 수 있다.

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