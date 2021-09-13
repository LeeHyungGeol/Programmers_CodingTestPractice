// �̺�Ž��(�Ķ��Ʈ����ġ), �ִ��� �ڷ��� casting�� ��������!!

// (���� ��� 2) ���̰���(1561��) ������ ����ϴ�.

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