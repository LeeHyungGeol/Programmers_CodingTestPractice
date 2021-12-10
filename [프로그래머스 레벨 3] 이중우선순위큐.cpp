#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

multiset<int> MS;
stringstream SS;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2, 0);

    for (string operation : operations) {
        char op;
        int num;
        SS.clear();
        SS.str(operation);
        SS >> op >> num;

        if (op == 'I') MS.insert(num);
        else if (!MS.empty() && op == 'D') {
            if (num == 1) MS.erase(--MS.end());
            else MS.erase(MS.begin());
        }
    }

    if (MS.empty()) return answer;

    answer[0] = *(--MS.end());
    answer[1] = *MS.begin();

    return answer;
}