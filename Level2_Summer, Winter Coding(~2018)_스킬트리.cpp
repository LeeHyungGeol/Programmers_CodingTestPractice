//입출력 예
// skill  |            skill_trees	             |    return
// "CBD"  |  ["BACDE", "CBADF", "AECB", "BDA"]	 |      2
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); ++i) {
        int index = 0;
        bool flag = true;
        for (int j = 0; j < skill_trees[i].size(); ++j) {
            if (skill.find(skill_trees[i][j]) != string::npos) {
                if (skill.find(skill_trees[i][j]) == index) index++;
                else { flag = false; break; }
            }
        }
        if (flag) answer++;
    }
    return answer;
}
int main() {
    string skill = "CBD";
    vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
    cout << solution(skill, skill_trees) << '\n';
    return 0;
}