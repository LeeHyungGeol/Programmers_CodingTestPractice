#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> fir = { 1, 2, 3, 4, 5 };
vector<int> sec = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> thi = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> answers = { 1,3,2,4,2 };//{1,2,3,4,5}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int n = answers.size();

    for (int i = 0; i < n; ++i) {
        if (fir[i % 5] == answers[i]) cnt1++;
        if (sec[i % 8] == answers[i]) cnt2++;
        if (thi[i % 10] == answers[i]) cnt3++;
    }

    int Max = max(cnt1, max(cnt2, cnt3));

    if (Max == cnt1) answer.push_back(1);
    if (Max == cnt2) answer.push_back(2);
    if (Max == cnt3) answer.push_back(3);

    sort(answer.begin(), answer.end());

    return answer;
}
int main() {
    vector<int> ans = solution(answers);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}