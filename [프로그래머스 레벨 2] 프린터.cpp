#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool flag = false;
    priority_queue<int> pq;
    queue<pii> q;

    for (int i = 0; i < priorities.size(); ++i) {
        pq.push(priorities[i]);
        q.push({ priorities[i], i });
    }

    while (!q.empty()) {
        int priority = pq.top();
        pii fileSequence = q.front();

        if (priority > fileSequence.first) {
            q.push(fileSequence);
            q.pop();
        }
        else {
            if (fileSequence.second == location) {
                flag = true;
            }
            pq.pop();
            q.pop();
            ++answer;
        }

        if (flag) {
            break;
        }
    }

    return answer;
}