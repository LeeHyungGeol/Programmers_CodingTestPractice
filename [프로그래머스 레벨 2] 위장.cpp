#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, vector<string>> map;

    // ���� ����(����, ����, �ѿ�...)�� map�� key�� �Ͽ� �����ش�.
    for (auto cloth : clothes) {
        map[cloth[1]].push_back(cloth[0]);
    }

    // ���� ���� + 1�� ��� ����� ���� ���Ѵ�.(+ 1�� ���ִ� ������ �ƹ��͵� �������� ���� ����� ���� �߰��� ��)
    for (auto m : map) {
        answer *= m.second.size() + 1;
    }

    // ��� ������ ���� �Ѱ����� �������� ���� ����� �� 1�� �� ���� answer�̴�.
    // ex) ���� 4��, ���� 5��, �ѿ� 3���� �ִٰ� �� ��, �� ����� ���� (4 + 1) * (5 + 1) * (3 + 1) = 120�����̴�. 
    // ���� ���� �� ��, ���� ���� �� ��, �ѿ� ���� �� ���� ���ԵǾ� �����Ƿ� 1�� ���ִ� ���̴�.
    return answer - 1;
}