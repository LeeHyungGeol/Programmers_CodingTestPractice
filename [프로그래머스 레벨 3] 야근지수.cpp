#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    priority_queue<ll> pq;

    for (int work : works) {
        pq.push(work);
    }

    while (n) {
        int Max = pq.top();
        pq.pop();
        pq.push(--Max);
        --n;
    }

    while (!pq.empty()) {
        if (pq.top() <= 0) {
            pq.pop();
            continue;
        }
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}