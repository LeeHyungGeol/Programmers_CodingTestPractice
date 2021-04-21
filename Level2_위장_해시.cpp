#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> m;

    // ���� ����(����, ����, �ѿ�...)�� map�� key�� �Ͽ� �����ش�.
    for (int i = 0; i < clothes.size(); ++i) {
        m[clothes[i][1]]++;
    }

    // ���� ���� + 1�� ��� ����� ���� ���Ѵ�.(+ 1�� ���ִ� ������ �ƹ��͵� �������� ���� ����� ���� �߰��� ��)
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        answer *= iter->second + 1;
    }

    // ��� ������ ���� �Ѱ����� �������� ���� ����� �� 1�� �� ���� answer�̴�.
    // ex) ���� 4��, ���� 5��, �ѿ� 3���� �ִٰ� �� ��, �� ����� ���� (4 + 1) * (5 + 1) * (3 + 1) = 120�����̴�. 
    // ���� ���� �� ��, ���� ���� �� ��, �ѿ� ���� �� ���� ���ԵǾ� �����Ƿ� 1�� ���ִ� ���̴�.
    return answer - 1;
}