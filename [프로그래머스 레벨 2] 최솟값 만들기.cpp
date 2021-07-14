// 정렬(sort) 문제
// 오름차순, 내림차순 정렬 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    //sort(B.rbegin(), B.rend());

    for (int i = 0; i < A.size(); ++i) {
        answer += A[i] * B[i];
    }

    return answer;
}