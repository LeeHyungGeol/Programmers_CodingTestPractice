#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

queue<pii> Q;
priority_queue<int> PQ;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for (int i = 0; i < priorities.size(); ++i) {
        Q.push({ priorities[i], i });
        PQ.push(priorities[i]);
    }

    while (!Q.empty()) {
        int job = Q.front().first;
        int index = Q.front().second;
        Q.pop();

        if (PQ.top() > job) {
            Q.push({ job, index });
        }
        else if (index == location) {
            ++answer;
            break;
        }
        else {
            ++answer;
            PQ.pop();
        }
    }

    return answer;
}