#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n = 5;
vector<int> lost = { 3,4,5 };
vector<int> reserve = { 2,3,4 };
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n + 1, 1);
    for (int i = 0; i < lost.size(); ++i)
        students[lost[i]]--;

    for (int i = 0; i < reserve.size(); ++i)
        students[reserve[i]]++;


    for (int i = 0; i < lost.size(); ++i) {
        if (students[lost[i]] == 0 && (lost[i] - 1) >= 1 && students[lost[i] - 1] == 2) {
            students[lost[i] - 1]--;
            students[lost[i]]++;
        }
        else if (students[lost[i]] == 0 && (lost[i] + 1) <= n && students[lost[i] + 1] == 2) {
            students[lost[i] + 1]--;
            students[lost[i]]++;
        }
    }


    for (int i = 1; i <= n; ++i) {
        if (students[i] > 0)
            answer++;
    }
    return answer;
}int main() {
    cout << solution(n, lost, reserve) << '\n';
}