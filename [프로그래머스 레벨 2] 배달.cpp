// �׷��� �ִܰŸ� �˰��� ����
// �������� ����ġ�� �ٸ��Ƿ�, ���ͽ�Ʈ�� Ȥ�� �÷��̵� ���ȷ� ������ Ǯ �� �ִ�.
// ����� ����(N)�� 50�� �����̹Ƿ�, �÷��̵� ���� �˰������� ����� �ð� ���� ���� Ǯ �� �����Ŷ�� �Ǵ��ϰ�,
// �ش� �˰����� �����Ͽ� Ǯ����.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
vector<vector<int>> Graph;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    Graph.resize(N, vector<int>(N, INF));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) Graph[i][j] = 0;
        }
    }

    for (vector<int> r : road) {
        Graph[r[0] - 1][r[1] - 1] = min(Graph[r[0] - 1][r[1] - 1], r[2]);
        Graph[r[1] - 1][r[0] - 1] = min(Graph[r[1] - 1][r[0] - 1], r[2]);
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                Graph[i][j] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (Graph[0][i] <= K) ++answer;
    }

    return answer;
}