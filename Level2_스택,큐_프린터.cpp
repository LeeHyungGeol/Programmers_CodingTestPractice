#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pii> q;
    for (int i = 0; i < priorities.size(); ++i) {
        pq.push(priorities[i]);
        q.push({ priorities[i], i });
    }
    while (!q.empty()) {
        int num = q.front().first;
        int idx = q.front().second;
        q.pop();
        if (pq.top() == num) {
            answer++;
            pq.pop();
            if (location == idx) break;
        }
        else {
            q.push({ num, idx });
        }
    }
    return answer;
}