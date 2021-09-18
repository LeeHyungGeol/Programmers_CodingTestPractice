// Set, multiSet은 내부적으로 항상 오름차순으로 정렬한다.

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);
    multiset<int> Set;

    for (string op : operations) {
        stringstream ss;
        ss.str(op);
        char cmd;
        int num;

        ss >> cmd >> num;

        if (cmd == 'I') {
            Set.insert(num);
        }
        else if (!Set.empty() && cmd == 'D') {
            if (num == 1) {
                Set.erase(--Set.end());
            }
            else if (num == -1) {
                Set.erase(Set.begin());
            }
        }
    }

    if (Set.empty()) {
        return answer;
    }
    else {
        answer[0] = *(--Set.end());
        answer[1] = *(Set.begin());
    }
    return answer;
}