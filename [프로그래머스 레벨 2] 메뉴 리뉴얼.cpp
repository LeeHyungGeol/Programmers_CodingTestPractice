// dfs, ����, ���� Ž��

//map -> vector �ű��, ó�� �� �����̴� �������!!!
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

// ���� ��� 1
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

// ���� ��� 2
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

    // ��� ������ �� ã�Ƴ���.
    for (auto order : orders) {
        // �ߺ� ������ �ƴ� �ܼ� ������ ���ؼ� ���ڿ��� ���� ������ �����Ѵ�. // "AX", "XA"�� ���տ��� ���� ��
        sort(order.begin(), order.end());
        for (auto size : course) {
            string temp = "";
            temp.resize(size);
            dfs(map, order, temp, 0, 0);
            // dfs2(map, order, "", 0, 0, size);
        }
    }

    vector<psi> courseComb;

    // ���� ���� ������ �ֹ� ���յ��� answer�� �ĺ��̹Ƿ� 1�� ������ �͵��� �ڸ���.
    for (auto m : map) {
        if (m.second > 1)
            courseComb.push_back(m);
    }

    // ������ ���� Ƚ���� ����, ���� Ƚ���� ���ٸ� ������ ���̰� ª�� ������ �����Ѵ�.
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