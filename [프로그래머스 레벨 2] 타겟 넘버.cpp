// dfs/bfs 문제
// 재귀를 사용하므로 dfs문제라고 할 수 있다. 
// 모든 경우의 수를 탐색하므로 완전탐색하기 위해 dfs를 이용한다.

// (백준 실버 1) 14888번 연산자 끼워넣기 와 매우 유사한 문제 

// 3번째 푼다.

#include <string>
#include <vector>

using namespace std;

int Answer;
void dfs(vector<int> numbers, int target, int sum, int index);

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return Answer;
}

void dfs(vector<int> numbers, int target, int sum, int index) {
    if (index == numbers.size()) {
        if (sum == target) {
            ++Answer;
        }
        return;
    }
    dfs(numbers, target, sum + numbers[index], index + 1);
    dfs(numbers, target, sum - numbers[index], index + 1);
}