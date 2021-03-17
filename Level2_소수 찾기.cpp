//https://mjmjmj98.tistory.com/38
//#include <algorithm>�� next_permutation() �Լ� ���
//do{} while(vector.begin(), vector.end());
//1. ������������ ���ĵ� ���� ���� �����̳ʷθ� ��밡���մϴ�.
//2. default�� operator < �� ����� ������ �����մϴ�.�� ������������ ������ �����մϴ�.
//3. �ߺ��� �ִ� ���ҵ��� �ߺ��� �����ϰ� ������ ������ݴϴ�.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool isPrimeNumber(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> arr;
    vector<int> ans;
    for (int i = 0; i < numbers.size(); ++i) arr.push_back(numbers[i] - '0');
    sort(arr.begin(), arr.end());
    do {
        for (int i = 0; i <= arr.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + arr[j];
                cout << " tmp : " << tmp << ", arr[j] : " << arr[j] << '\n';
                ans.push_back(tmp);
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); ++i) if (isPrimeNumber(ans[i])) answer++;

    return answer;
}
int main() {
    string numbers = "17";
    cout << solution(numbers) << '\n';

    return 0;
}