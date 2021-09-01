// dfs, 조합, 완전 탐색

// map -> vector 옮기기
// vector<psi> vector(map.begin(), map.end());
// vector.assing(Map.begin(), Map.end());

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<string, int> psi;

map<string, int> Map;
vector<psi> Combinations;

void dfs(int startIndex, int cnt, int length, string order, string temp);
bool compare(const psi& a, const psi& b);

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string order : orders) {
        sort(order.begin(), order.end());

        for (int length : course) {
            string temp = "";
            dfs(0, 0, length, order, temp);
        }
    }

    for (auto m : Map) {
        if (m.second > 1) {
            Combinations.push_back(m);
        }
    }

    sort(Combinations.begin(), Combinations.end(), compare);

    for (int courseLength : course) {
        int Max = 0;
        for (auto comb : Combinations) {
            if (comb.first.length() == courseLength) {
                if (Max == 0) {
                    answer.push_back(comb.first);
                    Max = comb.second;
                }
                else if (Max == comb.second) {
                    answer.push_back(comb.first);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

void dfs(int startIndex, int cnt, int length, string order, string temp) {
    if (cnt == length) {
        ++Map[temp];
        return;
    }

    for (int i = startIndex; i < order.size(); ++i) {
        temp.push_back(order[i]);
        dfs(i + 1, cnt + 1, length, order, temp);
        temp.pop_back();
    }
}

bool compare(const psi& a, const psi& b) {
    if (a.second == b.second) {
        return a.first.length() < b.first.length();
    }
    return a.second > b.second;
}

//-----------------------2번째 풀이--------------------------//

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<string, int> psi;

map<string, int> Map;
vector<int> Count(11, 0);

void dfs(int startIndex, int cnt, int length, string order, string temp);

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string order : orders) {
        sort(order.begin(), order.end());

        for (int length : course) {
            string temp = "";
            dfs(0, 0, length, order, temp);
        }
    }

    for (auto m : Map) {
        if (m.second >= 2 && m.second == Count[m.first.length()]) {
            answer.push_back(m.first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

void dfs(int startIndex, int cnt, int length, string order, string temp) {
    if (cnt == length) {
        ++Map[temp];
        Count[length] = max(Count[length], Map[temp]);
        return;
    }

    for (int i = startIndex; i < order.size(); ++i) {
        temp.push_back(order[i]);
        dfs(i + 1, cnt + 1, length, order, temp);
        temp.pop_back();
    }
}