// 이분탐색(파라메트릭서치), 최댓값의 자료형 casting에 유의하자!!

// (백준 골드 2) 놀이공원(1561번) 문제와 비슷하다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 0;

    ll start = 1, end = (ll)1000000000 * n;

    while (start <= end) {
        ll mid = (start + end) / 2;
        ll totalPerson = 0;

        for (int i = 0; i < times.size(); ++i) {
            totalPerson += mid / times[i];
        }

        if (totalPerson < n) {
            start = mid + 1;
        }
        else {
            answer = mid;
            end = mid - 1;
        }
    }

    return answer;
}