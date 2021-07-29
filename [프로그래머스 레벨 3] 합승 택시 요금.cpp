// 최단경로 알고리즘(프로이드 워셜)
// 모든 노드에서 다른 모든 노드까지의 최소 비용을 구하는 알고리즘
// n(노드의 갯수)의 최댓값이 200이므로 500개가 되지 않으므로, 
// 다익스트라 알고리즘이 아닌 플로이드 워셜 알고리즘을 적용 가능하다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF 1e9

using namespace std;

vector<vector<long long>> dist;

long long solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;

    dist.resize(n + 1, vector<long long>(n + 1, INF));

    for (int i = 0; i < fares.size(); ++i) {
        int a = fares[i][0];
        int b = fares[i][1];
        int cost = fares[i][2];

        dist[a][b] = cost;
        dist[b][a] = cost;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }

    return answer;
}