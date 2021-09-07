// 투 포인터, Set, Map

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

map<string, int> Map;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    set<string> Set(gems.begin(), gems.end());

    int start = 0, end = 0;

    for (string gem : gems) {
        ++Map[gem];
        if (Map.size() == Set.size()) {
            break;
        }
        ++end;
    }

    int result = end - start;
    int right = end;
    int left = start;

    while (end < gems.size()) {
        while (Map[gems[start]] > 1) {
            --Map[gems[start++]];
        }
        if (result > end - start) {
            result = end - start;
            right = end;
            left = start;
        }
        ++end;
        if (end == gems.size()) {
            break;
        }
        ++Map[gems[end]];
    }

    answer.push_back(left + 1);
    answer.push_back(right + 1);

    return answer;
}