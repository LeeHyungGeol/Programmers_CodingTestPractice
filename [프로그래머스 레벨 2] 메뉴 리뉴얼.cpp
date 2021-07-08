// dfs, 조합, 완전 탐색

//map -> vector 옮기기, 처음 안 내용이니 기억하자!!!
//vector<psi> vector(map.begin(), map.end());

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<string, int> psi;

bool comp(const psi& a, const psi& b) {
    if (a.second == b.second) {
        return a.first.length() < b.first.length();
    }
    return a.second > b.second;
}

// 조합 방식 1
void dfs(map<string, int>& map, string& order, string temp, int startIndex, int cnt) {
    if (cnt == temp.length()) {
        map[temp]++;
        return;
    }

    for (int i = startIndex; i < order.size(); ++i) {
        temp[cnt] = order[i];
        dfs(map, order, temp, i + 1, cnt + 1);
    }
}

// 조합 방식 2
void dfs2(map<string, int>& map, string& order, string temp, int startIndex, int cnt, int size) {
    if (cnt == size) {
        map[temp]++;
        return;
    }

    for (int i = startIndex; i < order.size(); ++i) {
        temp.push_back(order[i]);
        dfs2(map, order, temp, i + 1, cnt + 1, size);
        temp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> map;

    // 모든 조합을 다 찾아낸다.
    for (auto order : orders) {
        // 중복 조합이 아닌 단순 조합을 위해서 문자열을 사전 순으로 정렬한다. // "AX", "XA"는 조합에서 같은 것
        sort(order.begin(), order.end());
        for (auto size : course) {
            string temp = "";
            temp.resize(size);
            dfs(map, order, temp, 0, 0);
            // dfs2(map, order, "", 0, 0, size);
        }
    }

    vector<psi> courseComb;

    // 가장 많이 등장한 주문 조합들이 answer의 후보이므로 1번 나오는 것들은 자른다.
    for (auto m : map) {
        if (m.second > 1)
            courseComb.push_back(m);
    }

    // 조합의 등장 횟수가 많고, 등장 횟수가 같다면 조합의 길이가 짧은 순으로 정렬한다.
    sort(courseComb.begin(), courseComb.end(), comp);

    for (auto size : course) {
        int Max = 0;
        for (auto c : courseComb) {
            if (size == c.first.length()) {
                if (Max == 0) {
                    Max = c.second;
                    answer.push_back(c.first);
                }
                else if (Max == c.second) {
                    answer.push_back(c.first);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {

    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    solution(orders, course);
    return 0;
}