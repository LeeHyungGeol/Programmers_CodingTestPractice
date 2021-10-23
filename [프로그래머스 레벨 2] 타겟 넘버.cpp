// dfs/bfs ����
// ��͸� ����ϹǷ� dfs������� �� �� �ִ�. 
// ��� ����� ���� Ž���ϹǷ� ����Ž���ϱ� ���� dfs�� �̿��Ѵ�.

// (���� �ǹ� 1) 14888�� ������ �����ֱ� �� �ſ� ������ ���� 

// 3��° Ǭ��.

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