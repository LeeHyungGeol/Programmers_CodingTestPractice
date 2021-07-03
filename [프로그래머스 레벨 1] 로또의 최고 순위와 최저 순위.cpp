#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int getScore(int cnt) {
    if (cnt == 6) {
        return 1;
    }
    else if (cnt == 5) {
        return 2;
    }
    else if (cnt == 4) {
        return 3;
    }
    else if (cnt == 3) {
        return 4;
    }
    else if (cnt == 2) {
        return 5;
    }
    else {
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> set;
    int cnt0 = 0, cnt = 0;

    for (int i = 0; i < lottos.size(); ++i) {
        if (lottos[i] == 0) {
            ++cnt0;
        }
        set.insert(win_nums[i]);
    }

    for (auto lotto : lottos) {
        if (set.find(lotto) != set.end()) {
            ++cnt;
        }
    }

    answer.push_back(getScore(cnt + cnt0));
    answer.push_back(getScore(cnt));

    return answer;
}