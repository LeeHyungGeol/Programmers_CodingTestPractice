// 시뮬레이션(구현) 문제
// 카카오 다운 엄청 빡센 구현 문제이다.
// 한번에 바로 풀지는 못하고 다른 사람의 풀이를 참고하여 풀었다.
// 이코테 책에 있는 풀이보다 더 간단한 풀이인 set을 활용한 풀이이다.
// 그대로 vector를 이용할 수도 있겠지만 그렇게 하면 더욱 머리가 아파진다.

// set.insert() : 
// 이미 존재하는 원소의 경우 : 0 (삽입 불가 : set.insert().second), 
// 존재하지 않는 원소 삽입 : 1 (삽입 가능 :set.insert().second)

// set.erase() : 
// 이미 존재하는 원소 삭제 : 1(삭제 완료), 
// 존재하지 않는 원소 삭제 : 0(삭제 불가)

// set.find() :
// 존재하지 않는 원소를 find할 경우 : set.end()를 리턴한다. : set.find(x) == set.end()

#include <string>
#include <vector>
#include <set>

#define isExist(num) (set.find(conditions[num]) != set.end())

using namespace std;

bool isValid(const set<vector<int>>& set) {
    // 매 케이스 마다 현재까지 설치된 것들을 전부 검사
    for (auto frame : set) {
        int x = frame[0], y = frame[1], a = frame[2];

        // 기둥인 경우
        if (a == 0) {
            // 다른 기둥 위에 있는 경우, 보의 오른쪽 끝 부분 위, 보의 왼쪽 끝 부분 위의 경우
            vector<int> conditions[3] = { {x, y - 1, 0}, {x - 1, y, 1,}, {x,y,1} };
            // 기둥이 바닥 위에 있는 경우 까지
            if (y == 0 || isExist(0) || isExist(1) || isExist(2)) {
                continue;
            }

            return false;
        }
        // 보인 경우
        else {
            // 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결
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

        // 설치하는 경우
        if (b == 1) {
            // 일단 설치한다.
            set.insert(v);
            
            // 이때까지 설치한 것들과 비교했을 때 타당하지 않은 설치이면 삭제
            if (!isValid(set)) {
                set.erase(v);
            }
        }
        // 삭제하는 경우
        else {
            set.erase(v);

            // 이때까지 설치한 것들과 비교했을 때 타당하지 않은 삭제이면 다시 설치
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