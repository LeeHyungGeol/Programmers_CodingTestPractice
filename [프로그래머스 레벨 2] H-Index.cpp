#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();

    sort(citations.begin(), citations.end());

    int h = 1, cnt = 0;

    for (int h = 1; h <= n; ++h) {
        for (int j = 0; j < n; ++j) {
            if (h <= citations[j]) {
                ++cnt;
            }
        }

        if (cnt >= h && n - cnt <= h) {
            answer = h;
        }

        cnt = 0;
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