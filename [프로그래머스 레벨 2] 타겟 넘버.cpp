// dfs/bfs ����
// ��͸� ����ϹǷ� dfs������� �� �� �ִ�. 
// ��� ����� ���� Ž���ϹǷ� ����Ž���ϱ� ���� dfs�� �̿��Ѵ�.

// (���� �ǹ� 1) 14888�� ������ �����ֱ� �� �ſ� ������ ���� 

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