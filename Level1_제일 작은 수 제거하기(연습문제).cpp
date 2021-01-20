//정수를 저장한 배열, arr 에서 가장 작은 수를 제거한 배열을 리턴하는 함수, solution을 완성해주세요. 
//단, 리턴하려는 배열이 빈 배열인 경우엔 배열에 -1을 채워 리턴하세요. 
//예를들어 arr이 [4,3,2,1]인 경우는 [4,3,2]를 리턴 하고, [10]면 [-1]을 리턴 합니다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;

    int nMin = *min_element(arr.begin(), arr.end());
    int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();
    answer.erase(answer.begin() + pos);

    return answer.empty() ? vector<int>(1, -1) : answer;
}
vector<int> solution2(vector<int> arr) {
    vector<int> answer;
    int minIndex = 0, min = arr[0];
    if (arr.size() == 1) answer.push_back(-1);
    else {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] < min) {
                min = arr[i];
                minIndex = i;
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (minIndex == i) continue;
            answer.push_back(arr[i]);
        }
    }
    return answer;
}