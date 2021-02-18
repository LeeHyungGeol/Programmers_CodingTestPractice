#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < speeds.size(); ++i) {
        int days = 0;
        ((100 - progresses[i]) % speeds[i]) ? days = ((100 - progresses[i]) / speeds[i]) + 1 : days = ((100 - progresses[i]) / speeds[i]);
        q.push(days);
    }
    int cnt = 0;
    int days = q.front();
    while (!q.empty()) {
        if (days < q.front()) {
            //cout<<"days: "<<days<<" cnt: "<<cnt<<'\n';
            answer.push_back(cnt);
            days = q.front();
            cnt = 1;
        }
        else {
            //cout<<"days: "<<days<<" cnt: "<<cnt<<'\n';
            cnt++;
        }
        q.pop();
    }
    answer.push_back(cnt);
    return answer;
}
