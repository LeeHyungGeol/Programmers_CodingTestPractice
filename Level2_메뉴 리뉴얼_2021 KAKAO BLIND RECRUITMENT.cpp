//Trie ����?? 
//�ƴϾ���. �׳� ������ ��� ������ �غ��� brute force����

//map -> vector �ű��, ó�� �� �����̴� �������!!!
//vector<psi> vector(map.begin(), map.end());

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<string, int> psi;

bool cmp(const psi& a, const psi& b) {
    return a.second > b.second;
}
//������ ��� ���� ã�� ex) ABCFG -> AB, AC, AF, AG, BC, BF, BG...
void findAllcases(map<string, int>& m, int maxSize, string order, string newCourse, int index) {
    cout << newCourse << '\n';
    //������ �޴� ���� ������ �ִ��϶��� return
    if (newCourse.size() == maxSize) {
        //���ο� �޴� ������ �̹� �ִٸ� +1
        if (m.find(newCourse) != m.end()) m[newCourse] += 1;
        //���ο� �޴� ������ ���ٸ� ���� �߰�
        else m[newCourse] = 1;
        return;
    }
    //��� ȣ��� ���� ã��
    for (int i = index; i < order.size(); ++i) {
        cout << "index : " << index << ", i : " << i << '\n';
        findAllcases(m, maxSize, order, newCourse + order[i], i + 1);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); ++i) {
        map<string, int> allCases;
        for (int j = 0; j < orders.size(); ++j) {
            sort(orders[j].begin(), orders[j].end());
            //corse�� ���̺��� �ֹ��� ���� ���̰� ũ�ų� ���� ���� ������ ��� ������ ã�ƺ� �� �ִ�.
            if (course[i] <= orders[j].size()) findAllcases(allCases, course[i], orders[j], "", 0);
        }
        //map -> vector �ű��
        vector<psi> v(allCases.begin(), allCases.end());

        //������� ���� ������ ���� �������� ���� 
        sort(v.begin(), v.end(), cmp);

        if (!v.empty()) {
            //�ִ� ���� ũ�⸸ŭ ���信 ����
            int biggest = v[0].second;

            //�ּ� 2�� �̻� �մ����κ��� �ֹ��� �����̾�� �ϹǷ�
            if (v[0].second >= 2) {
                for (int i = 0; i < v.size(); i++) {
                    if (v[i].second == v[0].second) answer.push_back(v[i].first);
                    else break;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {

    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2,3,4 };
    solution(orders, course);
    return 0;
}