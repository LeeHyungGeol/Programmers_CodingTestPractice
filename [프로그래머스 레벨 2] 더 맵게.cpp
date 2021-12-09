#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct Node {
    int x;

    bool operator < (const Node& other) const {
        return x > other.x;
    }
}Node;

priority_queue<Node> PQ;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (int s : scoville) {
        PQ.push({ s });
    }

    while (!PQ.empty()) {
        if (PQ.top().x >= K) break;
        if (PQ.size() < 2) return answer = -1;
        int first = PQ.top().x;
        PQ.pop();
        int second = PQ.top().x;
        PQ.pop();
        PQ.push({ first + 2 * second });
        ++answer;
    }

    return answer;
}