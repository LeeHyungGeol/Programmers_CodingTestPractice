//������ ������ �迭, arr ���� ���� ���� ���� ������ �迭�� �����ϴ� �Լ�, solution�� �ϼ����ּ���. 
//��, �����Ϸ��� �迭�� �� �迭�� ��쿣 �迭�� -1�� ä�� �����ϼ���. 
//������� arr�� [4,3,2,1]�� ���� [4,3,2]�� ���� �ϰ�, [10]�� [-1]�� ���� �մϴ�.
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