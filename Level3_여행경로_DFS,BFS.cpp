#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string start, vector<vector<string>>& tickets, vector<string> route, vector<string>& answer, vector<bool>& visited, int count) {
    route.push_back(start);

    //경로 끝까지 다 이어졌는지 확인.
    if (count == tickets.size()) {
        answer = route; // save current path.
        return true;
    }

    for (int i = 0; i < tickets.size(); ++i) {
        if (start == tickets[i][0] && visited[i] == false) {
            visited[i] = true;

            bool success = dfs(tickets[i][1], tickets, route, answer, visited, count + 1);

            //경로 찾기에 성공한 경우, 더 이상 dfs를 진행하지 않아야 하므로
            if (success) {
                return true; // exit dfs.
            }

            visited[i] = false;
        }
    }

    route.pop_back();

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, route;
    vector<bool> visited(tickets.size(), false);

    sort(tickets.begin(), tickets.end());

    dfs("ICN", tickets, route, answer, visited, 0);

    return answer;
}