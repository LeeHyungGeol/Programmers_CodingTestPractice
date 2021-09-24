#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b);

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int flag = -30001;

    sort(routes.begin(), routes.end(), compare);

    for (vector<int> route : routes) {
        if (flag < route[0]) {
            ++answer;
            flag = route[1];
        }
    }

    return answer;
}

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}