#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

map<int, int> Map;
vector<pii> Subsets;

bool compare(const pii& a, const pii& b);

vector<int> solution(string s) {
    vector<int> answer;

    string number = "";

    for (int i = 0; i < s.length(); ++i) {
        if (isdigit(s[i])) {
            number += s[i];
        }
        else {
            if (!number.empty()) {
                ++Map[stoi(number)];
                number = "";
            }
        }
    }

    Subsets.assign(Map.begin(), Map.end());

    sort(Subsets.begin(), Subsets.end(), compare);

    for (pii x : Subsets) {
        answer.push_back(x.first);
    }

    return answer;
}

bool compare(const pii& a, const pii& b) {
    return a.second > b.second;
}