#include <string>
#include <vector>
//��Ŭ���� ȣ���� �ð� ���⵵: O(logN)
using namespace std;
int Euclidean(int a, int b) {
    return b ? Euclidean(b, a % b) : a;
}
int getGCD(int a, int b) {
    if (a < b)
        swap(a, b);
    if (a % b == 0) return b;
    else return getGCD(b, a % b);
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(getGCD(n, m));
    answer.push_back(n * m / answer[0]);
    return answer;
}