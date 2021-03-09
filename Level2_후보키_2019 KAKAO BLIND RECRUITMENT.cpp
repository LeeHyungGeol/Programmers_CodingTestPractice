//비트마스크 혹은 dfs로 풀 수 있는 문제
//map을 사용하여 조합을 여러가지로 하여 풀어보려 했지만 코드가 너무 복잡해질 것 같아서 포기
//검색해보았더니 set과 비트마스크를 이용한 풀이가 가장 깔끔하고 실용적이라고 판단
//다시 한번 비트마스크를 공부하고 적용해보았다.
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
//후보키의 최소성을 검사하는 함수
bool key_min(vector<int>& ans, int now) {
    for (int i = 0; i < ans.size(); ++i) {
        //예를 들어 ans[i]=0110이고, now=0111이 들어왔을 때 이것을 & 연산을 했을 때 0110이된다.
        //따라서 이미 있는 조합으로 되어버릴 경우 false를 반환
        if ((ans[i] & now) == ans[i]) return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    vector<int> answer;
    int row = relation.size();//가로의 개수
    int col = relation[0].size();//세로의 개수//속성의 개수
     // 조합 경우의 수
    /*
     1(0001) - 학번
     2(0010) - 이름
     3(0011) - 이름, 학번
     4(0100) - 전공
     5(0101) - 학번, 전공
     6(0110) - 이름, 전공
     7(0111) - 학번, 이름, 전공
     8(1000) - 학년
     9(1001) - 학번, 학년
     10(1010) - 이름, 학년
     11(1011) - 학번, 이름, 학년
     12(1100) - 이름, 학번
     13(1101) - 학번, 전공, 학년
     14(1110) - 이름, 전공, 학년
     15(1111) - 학번, 이름, 전공, 학년
     */
    for (int i = 1; i < (1 << col); ++i) {
        set<string> set;
        for (int j = 0; j < row; ++j) {
            string s = "";
            for (int k = 0; k < col; ++k) {
                if (i & (1 << k)) s += relation[j][k] + ' ';
            }
            //cout<<s<<'\n';
            //각각의 조합의 경우의 수의 string들을 set에 insert
            //유일성이 보장되지 않은 조합의 경우도 일단 들어간다.
            set.insert(s);
        }
        //유일성 + 최소성 검사
        //set의 size가 row의 개수(가로, 튜플의 개수)와 같아야 i에 해당하는 조합이 유일성이 보장된 키의 조합이라고 할 수 있다.
        //key_min() : 최소성을 검사하는 함수, answer에 들어있는 조합과 새로 만들어진 조합을 &연산하여 그 결과가 이미 answer에 포함되어 있으면 false를 반환, 없는 조합이라면 true를 반환
        //이 2가지 경우를 모두 만족시 answer.push_back() 가능
        if (set.size() == row && key_min(answer, i)) answer.push_back(i);
    }
    //answer.size()가 후보키의 총 개수
    return (int)answer.size();
}
int main() {
    vector<vector<string>> relation = { {"100","ryan","music","2"} ,{"200","apeach","math","2"},{"300","tube","computer","3"}
    ,{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"} };

    cout << solution(relation) << '\n';

    return 0;
}