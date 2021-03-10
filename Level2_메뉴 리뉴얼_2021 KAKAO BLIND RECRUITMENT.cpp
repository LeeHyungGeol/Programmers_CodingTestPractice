//Trie 문제?? 
//아니었음. 그냥 가능한 모든 조합을 해보는 brute force문제

//map -> vector 옮기기, 처음 안 내용이니 기억하자!!!
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
//가능한 모든 조합 찾기 ex) ABCFG -> AB, AC, AF, AG, BC, BF, BG...
void findAllcases(map<string, int>& m, int maxSize, string order, string newCourse, int index) {
    cout << newCourse << '\n';
    //조합이 메뉴 구성 길이의 최대일때만 return
    if (newCourse.size() == maxSize) {
        //새로운 메뉴 구성이 이미 있다면 +1
        if (m.find(newCourse) != m.end()) m[newCourse] += 1;
        //새로운 메뉴 구성이 없다면 새로 추가
        else m[newCourse] = 1;
        return;
    }
    //재귀 호출로 조합 찾기
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
            //corse의 길이보다 주문의 원래 길이가 크거나 같을 때만 가능한 모든 조합을 찾아볼 수 있다.
            if (course[i] <= orders[j].size()) findAllcases(allCases, course[i], orders[j], "", 0);
        }
        //map -> vector 옮기기
        vector<psi> v(allCases.begin(), allCases.end());

        //만들어진 조합 개수에 따라 내림차순 정렬 
        sort(v.begin(), v.end(), cmp);

        if (!v.empty()) {
            //최대 개수 크기만큼 정답에 저장
            int biggest = v[0].second;

            //최소 2명 이상 손님으로부터 주문된 조합이어야 하므로
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