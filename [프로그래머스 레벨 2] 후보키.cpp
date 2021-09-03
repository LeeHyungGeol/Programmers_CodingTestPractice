// Set, Bitmask, 완전탐색, Bit연산

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool check(vector<int> answer, int now);

int solution(vector<vector<string>> relation) {
    vector<int> answer;
    int n = relation.size();
    int m = relation[0].size();

    for (int i = 1; i < (1 << m); ++i) {
        set<string> set;
        for (int j = 0; j < n; ++j) {
            string str = "";
            for (int k = 0; k < m; ++k) {
                if (i & (1 << k)) {
                    str += relation[j][k] + ' ';
                }
            }
            set.insert(str);
        }

        if (set.size() == n && check(answer, i)) {
            for (auto it = set.begin(); it != set.end(); ++it) {
                cout << *it << '\n';
            }
            answer.push_back(i);
        }
    }

    return answer.size();
}

bool check(vector<int> answer, int now) {
    for (int i = 0; i < answer.size(); ++i) {
        if ((answer[i] & now) == answer[i]) {
            return false;
        }
    }
    return true;
}