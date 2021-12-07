// 그래프 최단거리 알고리즘 문제
// 간선마다 가중치가 다르므로, 다익스트라 혹은 플로이드 워셜로 문제를 풀 수 있다.
// 노드의 개수(N)이 50개 이하이므로, 플로이드 워셜 알고리즘으로 충분히 시간 제한 없이 풀 수 있을거라고 판단하고,
// 해당 알고리즘을 적용하여 풀었다.

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