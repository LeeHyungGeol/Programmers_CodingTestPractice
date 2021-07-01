// �ùķ��̼�(����) ����
// īī�� �ٿ� ��û ���� ���� �����̴�.
// �ѹ��� �ٷ� Ǯ���� ���ϰ� �ٸ� ����� Ǯ�̸� �����Ͽ� Ǯ����.
// ������ å�� �ִ� Ǯ�̺��� �� ������ Ǯ���� set�� Ȱ���� Ǯ���̴�.
// �״�� vector�� �̿��� ���� �ְ����� �׷��� �ϸ� ���� �Ӹ��� ��������.

// set.insert() : 
// �̹� �����ϴ� ������ ��� : 0 (���� �Ұ� : set.insert().second), 
// �������� �ʴ� ���� ���� : 1 (���� ���� :set.insert().second)

// set.erase() : 
// �̹� �����ϴ� ���� ���� : 1(���� �Ϸ�), 
// �������� �ʴ� ���� ���� : 0(���� �Ұ�)

// set.find() :
// �������� �ʴ� ���Ҹ� find�� ��� : set.end()�� �����Ѵ�. : set.find(x) == set.end()

#include <string>
#include <vector>
#include <set>

#define isExist(num) (set.find(conditions[num]) != set.end())

using namespace std;

bool isValid(const set<vector<int>>& set) {
    // �� ���̽� ���� ������� ��ġ�� �͵��� ���� �˻�
    for (auto frame : set) {
        int x = frame[0], y = frame[1], a = frame[2];

        // ����� ���
        if (a == 0) {
            // �ٸ� ��� ���� �ִ� ���, ���� ������ �� �κ� ��, ���� ���� �� �κ� ���� ���
            vector<int> conditions[3] = { {x, y - 1, 0}, {x - 1, y, 1,}, {x,y,1} };
            // ����� �ٴ� ���� �ִ� ��� ����
            if (y == 0 || isExist(0) || isExist(1) || isExist(2)) {
                continue;
            }

            return false;
        }
        // ���� ���
        else {
            // ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����
            vector<int> conditions[4] = { {x, y - 1, 0}, {x - 1, y, 1,}, {x + 1, y, 1}, {x + 1, y - 1, 0} };

            if (isExist(0) || isExist(3) || (isExist(1) && isExist(2))) {
                continue;
            }

            return false;
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> set;

    for (auto frame : build_frame) {
        int x = frame[0], y = frame[1], a = frame[2], b = frame[3];
        vector<int> v = { x, y, a };

        // ��ġ�ϴ� ���
        if (b == 1) {
            // �ϴ� ��ġ�Ѵ�.
            set.insert(v);
            
            // �̶����� ��ġ�� �͵�� ������ �� Ÿ������ ���� ��ġ�̸� ����
            if (!isValid(set)) {
                set.erase(v);
            }
        }
        // �����ϴ� ���
        else {
            set.erase(v);

            // �̶����� ��ġ�� �͵�� ������ �� Ÿ������ ���� �����̸� �ٽ� ��ġ
            if (!isValid(set)) {
                set.insert(v);
            }
        }
    }

    for (auto build : set) {
        answer.push_back(build);
    }

    return answer;
}