#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;

    vector<vector<int>> Graph(n + 1);
    vector<vector<int>> Dp(k, vector<int>(n + 1, INF));

    for (int i = 0; i < edge_list.size(); ++i) {
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    // DP[A][B] = C : ����� A�� ������ B�� �Ǿ��� ��, �����ؾ� �ϴ� Ƚ��
    // �ʱⰪ = DP[0][gps_log[0]] = 0
    // ������ ���� (0 ���� �������� �ּ� ����Ƚ���� 0)
    Dp[0][gps_log[0]] = 0;

    for (int t = 1; t < k; ++t) {
        for (int cur = 1; cur <= n; ++cur) {
            if (Dp[t - 1][cur] == INF) {
                continue;
            }

            for (int next : Graph[cur]) {
                int correction = 0;
                if (gps_log[t] != next) {
                    ++correction;
                }
                Dp[t][next] = min(Dp[t][next], Dp[t - 1][cur] + correction);
            }
        }
    }

    if (Dp[k - 1][gps_log[k - 1]] >= INF) {
        answer = -1;
    }
    else {
        answer = Dp[k - 1][gps_log[k - 1]];
    }

    return answer;
}