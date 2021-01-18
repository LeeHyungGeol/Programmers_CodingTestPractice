#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
vector<vector<int>> commands = { {2, 5, 3} ,{4, 4, 1},{1, 7, 3} };
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); ++i) {
        int first = commands[i][0] - 1;
        int last = commands[i][1] - 1;
        int k = commands[i][2];
        vector<int> arrCut;
        for (int j = first; j <= last; ++j)
            arrCut.push_back(array[j]);
        sort(arrCut.begin(), arrCut.end());
        answer.push_back(arrCut[k - 1]);
    }

    return answer;
}
vector<int> solution2(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for (int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2] - 2]);
    }

    return answer;
}

int main() {
    vector<int> ans = solution(arr, commands);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}