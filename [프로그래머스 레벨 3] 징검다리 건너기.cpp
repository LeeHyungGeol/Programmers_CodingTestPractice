#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 1, end = *max_element(stones.begin(), stones.end());

    while (start <= end) {
        int mid = (start + end) / 2;
        int cnt = 0;
        bool flag = false;

        for (int stone : stones) {
            if (stone - mid < 0) {
                ++cnt;
            }
            else {
                cnt = 0;
            }
            if (cnt >= k) {
                flag = true;
                break;
            }
        }

        if (flag) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
            answer = mid;
        }
    }

    return answer;
}