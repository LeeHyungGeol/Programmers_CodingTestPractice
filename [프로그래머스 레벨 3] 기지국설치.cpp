#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0, start = 1, index = 0;

    while (start <= n) {
        if (stations[index] - w <= start && start <= stations[index] + w) {
            start = stations[index] + w;
            ++index;
        }
        else {
            start += 2 * w;
            ++answer;
        }
        ++start;
    }

    return answer;
}