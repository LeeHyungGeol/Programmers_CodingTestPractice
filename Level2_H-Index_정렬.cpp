#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int maxCitation = 0;

    for (int h = 1; h <= citations.size(); ++h) {
        int count = 0;

        for (int j = 0; j < citations.size(); ++j) {
            if (citations[j] >= h) {
                count++;
            }
        }
        if (count >= h) {
            answer = max(answer, h);
        }
    }

    return answer;
}

int solution2(vector<int> citations) {
    int answer = 0;
    int total = citations.size();

    sort(citations.begin(), citations.end());

    for (int i = 0; i < citations.size(); ++i) {
        if (total - i <= citations[i]) {
            //answer++;
            answer = total - i;
            break;
        }
    }

    return answer;
}