#include <string>
#include <vector>
#include <queue>

using namespace std;

// �׻� �ּ� ���� �� �� �־�� �ϹǷ� heap(priority_queue)�� ����Ѵ�.
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;

    for (int i = 0; i < scoville.size(); ++i) {
        pq.push(-scoville[i]);
    }

    bool flag = false;

    while (true) {
        // ���� ���� ���� �ٷ� �˱� ���� pq.top()�� ����Ѵ�.
        if (-pq.top() >= K) {
            break;
        }
        // ���� �����ϱ� ���ؼ��� pq�� �ּ��� 2���� ���� �ʿ��ϹǷ� pq.size()�� �̿��Ͽ�
        // pq�� ũ�⸦ ���Ѵ�.
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