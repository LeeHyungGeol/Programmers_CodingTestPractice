// 우선순위큐, 연산자오버로딩(operator overloading)

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, i = 0, time = 0;
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;

    sort(jobs.begin(), jobs.end());

    while (i < (int)jobs.size() || !pq.empty()) {
        if (i < (int)jobs.size() && time >= jobs[i][0]) {
            pq.push(jobs[i]);
            ++i;
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else {
            time = jobs[i][0];
        }
    }

    return answer / (int)jobs.size();
}