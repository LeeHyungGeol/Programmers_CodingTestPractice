// �׷��� �ִܰŸ� �˰��� ����
// �������� ����ġ�� �ٸ��Ƿ�, ���ͽ�Ʈ�� Ȥ�� �÷��̵� ���ȷ� ������ Ǯ �� �ִ�.
// ����� ����(N)�� 50�� �����̹Ƿ�, �÷��̵� ���� �˰������� ����� �ð� ���� ���� Ǯ �� �����Ŷ�� �Ǵ��ϰ�,
// �ش� �˰����� �����Ͽ� Ǯ����.

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int graph[50][50] = { 0, };

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = INF;
            }
        }
    }

    for (auto info : road) {
        int a = info[0] - 1;
        int b = info[1] - 1;
        int cost = info[2];

        graph[a][b] = min(graph[a][b], cost);
        graph[b][a] = min(graph[b][a], cost);
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                graph[j][i] = min(graph[j][i], graph[j][k] + graph[k][i]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (graph[0][i] <= K) {
            ++answer;
        }
    }

    return answer;
}