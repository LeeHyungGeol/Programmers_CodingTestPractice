#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < speeds.size(); ++i) {
        q.push((99 - progresses[i]) / speeds[i] + 1);
    }

    while (!q.empty()) {
        int cnt = 1;
        int cur = q.front();
        q.pop();

        while (!q.empty() && cur >= q.front()) {
            ++cnt;
            q.pop();
        }

        answer.push_back(cnt);
    }

    return answer;
}