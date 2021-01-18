#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                answer.push_back(numbers[i] + numbers[j]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
vector<int> solution2(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i + 1; j < numbers.size(); ++j) {
            st.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(st.begin(), st.end());
    return answer;
}