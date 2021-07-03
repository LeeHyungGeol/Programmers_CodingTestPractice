// dfs/bfs 문제
// 재귀를 사용하므로 dfs문제라고 할 수 있다. 
// 모든 경우의 수를 탐색하므로 완전탐색하기 위해 dfs를 이용한다.

// (백준 실버 1) 14888번 연산자 끼워넣기 와 매우 유사한 문제 

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int index, int total, int target) {
    if (index == numbers.size()) {
        if (total == target)
            ++answer;
        return;
    }

    dfs(numbers, index + 1, total + numbers[index], target);
    dfs(numbers, index + 1, total - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    return answer;
}