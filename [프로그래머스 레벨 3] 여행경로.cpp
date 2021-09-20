// dfs/bfs, 조합 문제

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Result = "a";
vector<bool> Visited;

void dfs(vector<vector<string>>& tickets, int index, string start, string total);

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    Visited.resize(tickets.size(), false);

    dfs(tickets, 0, "ICN", "ICN");

    for (int i = 0; i < Result.size(); i += 3) {
        answer.push_back(Result.substr(i, 3));
    }

    return answer;
}

void dfs(vector<vector<string>>& tickets, int index, string start, string total) {
    if (index == tickets.size() && total < Result) {
        Result = total;
        return;
    }

    for (int i = 0; i < tickets.size(); ++i) {
        if (!Visited[i] && tickets[i][0] == start) {
            Visited[i] = true;
            dfs(tickets, index + 1, tickets[i][1], total + tickets[i][1]);
            Visited[i] = false;
        }
    }
}