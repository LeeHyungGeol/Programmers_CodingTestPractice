#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1, 2, 3, 4, 5 };
vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> three = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer, trio(3, 0);

    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == one[i % 5]) {
            ++trio[0];
        }
        if (answers[i] == two[i % 8]) {
            ++trio[1];
        }
        if (answers[i] == three[i % 10]) {
            ++trio[2];
        }
    }

    int Max = *max_element(trio.begin(), trio.end());

    for (int i = 0; i < 3; ++i) {
        if (trio[i] == Max) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
int main() {
    vector<int> ans = solution(answers);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}