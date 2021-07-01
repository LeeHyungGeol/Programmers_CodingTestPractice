#include <string>
#include <vector>
#include <queue>

using namespace std;

// 항상 최소 값을 알 수 있어야 하므로 heap(priority_queue)를 사용한다.
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;

    for (int i = 0; i < scoville.size(); ++i) {
        pq.push(-scoville[i]);
    }

    bool flag = false;

    while (true) {
        // 가장 위의 값을 바로 알기 위해 pq.top()을 사용한다.
        if (-pq.top() >= K) {
            break;
        }
        // 맛을 조합하기 위해서는 pq에 최소한 2개의 값이 필요하므로 pq.size()를 이용하여
        // pq의 크기를 구한다.
        if (pq.size() < 2) {
            flag = true;
            break;
        }

        int Min = -pq.top();
        pq.pop();

        int secondMin = -pq.top();
        pq.pop();

        int newMin = Min + 2 * secondMin;

        pq.push(-newMin);

        ++answer;
    }

    if (flag) {
        return -1;
    }

    return answer;
}