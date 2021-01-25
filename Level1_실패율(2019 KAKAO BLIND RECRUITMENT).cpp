#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<double, int> pdi;
bool compare(const pdi& a, const pdi& b) {
    //fisrt가 같다면 //second로 오름차순
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first; //first로 내림차순
}
vector<int> solution(int N, vector<int> stages) {
    vector<pdi> v;
    vector<int> answer;
    double m = stages.size(), cnt = 0;
    for (int stage = 1; stage <= N; ++stage) {
        cnt = 0;
        for (int j = 0; j < stages.size(); ++j) {
            if (stages[j] == stage) cnt++;
        }
        if (cnt == 0) {
            v.push_back({ 0, stage });
            continue;
        }
        v.push_back({ (cnt / m), stage });
        m -= cnt;
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); ++i)
        answer.push_back(v[i].second);
    return answer;
}int main() {
    int N = 8;
    vector<int> stages = { 7, 6, 5, 4, 3, 2, 1, 8 };
    vector<int> ans = solution(N, stages);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}