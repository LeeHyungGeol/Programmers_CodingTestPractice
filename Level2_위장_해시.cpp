#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> m;

    // 옷을 종류(상의, 하의, 겉옷...)를 map의 key로 하여 세어준다.
    for (int i = 0; i < clothes.size(); ++i) {
        m[clothes[i][1]]++;
    }

    // 옷의 종류 + 1로 모든 경우의 수를 구한다.(+ 1을 해주는 이유는 아무것도 선택하지 않을 경우의 수를 추가한 것)
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        answer *= iter->second + 1;
    }

    // 모든 종류의 옷을 한가지도 선택하지 않은 경우의 수 1을 뺀 것이 answer이다.
    // ex) 상의 4개, 하의 5개, 겉옷 3개가 있다고 할 때, 총 경우의 수는 (4 + 1) * (5 + 1) * (3 + 1) = 120가지이다. 
    // 상의 선택 안 함, 하의 선택 안 함, 겉옷 선택 안 함이 포함되어 있으므로 1을 빼주는 것이다.
    return answer - 1;
}