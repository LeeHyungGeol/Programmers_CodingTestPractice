#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, index = 0, sum = 0;
    queue<int> q;

    while (true) {
        ++answer;

        if (q.size() == bridge_length) {
            sum -= q.front();
            q.pop();
        }

        if (sum + truck_weights[index] <= weight) {
            if (index == truck_weights.size() - 1) {
                answer += bridge_length;
                break;
            }

            sum += truck_weights[index];
            q.push(truck_weights[index]);
            ++index;
        }
        else {
            q.push(0);
        }
    }

    return answer;
}