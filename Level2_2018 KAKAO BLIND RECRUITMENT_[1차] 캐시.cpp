//������ ��ü �˰����� ����¡ ������� �޸𸮸� �����ϴ� �ü������, 
//������ ���簡 �߻� �Ͽ� ���ο� �������� �Ҵ��ϱ� ���� ���� �Ҵ�� ������ �� ��� �Ͱ� ��ü������ �����ϴ� ����Դϴ�.

//LFU : ���� ���� Ƚ���� �����ϴ� �������� ��ü
//����: ������ ���ɼ��� �������� �ұ��ϰ� Ƚ���� ���� ����̹Ƿ� �ֱٿ� ���� ���α׷��� ��ü��ų ���ɼ��� �ְ�, �ش� Ƚ���� ������Ű�Ƿ� ������� �߻�

//LRU: ���� �������� �������� ���� �������� ��ü
//���� : ���μ����� �ֱ����ġ�� ������ ������ ������ �������� ���� �ð��� ����ؾ���.ū ������尡 �߻�

//���⼭�� LRU�˰����� ����ؾ� ��.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;

    for (int i = 0; i < cities.size(); ++i) {
        //���ڿ��� ���ĺ��� ��� �ҹ��ڷ� �ٲٴ� �Լ�
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        bool flag = true;
        //erase�Լ��� ����ϱ� ���� iterator�� ���
        for (auto it = v.begin(); it != v.end(); ++it) {
            //�޸𸮿� �ش� ���ڿ��� �ִ� ��� : hit
            if (*it == cities[i]) {
                flag = false;
                answer++;
                v.erase(it);
                v.push_back(cities[i]);
                break;
            }
        }
        //�޸𸮿� �ش� ���ڿ��� ���� ��� : page fault
        if (flag) {
            answer += 5;
            if (v.size() < cacheSize) v.push_back(cities[i]);
            else if (cacheSize != 0 && v.size() >= cacheSize) {
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
        }
    }

    return answer;
}