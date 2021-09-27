#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, size = A.size();
    int bIndex = 0;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    for (int i = 0; i < size; ++i) {
        for (int j = bIndex; j < size; ++j) {
            if (A[i] < B[j]) {
                ++answer;
                bIndex = j + 1;
                break;
            }
        }
    }

    return answer;
}