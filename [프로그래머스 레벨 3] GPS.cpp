#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
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

    // DP[A][B] = C : 경로의 A번 지점이 B가 되었을 때, 수정해야 하는 횟수
    // 초기값 = DP[0][gps_log[0]] = 0
    // 시작점 고정 (0 초의 시작점의 최소 수정횟수는 0)
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