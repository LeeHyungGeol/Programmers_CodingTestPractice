#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); ++i) {
        int days = ((100 - progresses[i]) / speeds[i]);

        if (((100 - progresses[i]) % speeds[i])) {
            ++days;
        }
        q.push(days);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int cnt = 1;

        while (!q.empty() && cur >= q.front()) {
            ++cnt;
            q.pop();
        }

        answer.push_back(cnt);
    }

    return answer;
}