// �ִܰ�� �˰���(�����̵� ����)
// ��� ��忡�� �ٸ� ��� �������� �ּ� ����� ���ϴ� �˰���
// n(����� ����)�� �ִ��� 200�̹Ƿ� 500���� ���� �����Ƿ�, 
// ���ͽ�Ʈ�� �˰����� �ƴ� �÷��̵� ���� �˰����� ���� �����ϴ�.

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